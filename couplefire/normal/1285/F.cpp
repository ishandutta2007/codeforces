#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, mu[N], occur[N];
bool flag[N];
vector<int> stuff[N], factors[N], primes, arr;
long long ans;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; arr.resize(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    ans = arr.back(); n = arr.size();
    for(int i = 1; i<N; i++)
        for(int j = 1; i*j<N; j++)
            factors[i*j].push_back(i);
    for(int i = 0; i<n; i++)
        for(int d : factors[arr[i]])
            stuff[d].push_back(arr[i]);
    mu[1] = 1;
    for(int i = 2; i<N; i++){
        if(!flag[i])
            primes.push_back(i), mu[i] = -1;
        for(int j = 0; j<(int)primes.size() && i*primes[j] < N; j++){
            flag[i*primes[j]] = 1;
            if(i%primes[j] == 0){
                mu[i*primes[j]] = 0;
                break;
            }
            mu[i*primes[j]] = -mu[i];
        }
    }
    for(int i = 1; i<N; i++){
        if((int)stuff[i].size() < 2) continue;
        stack<int> st;
        sort(stuff[i].begin(), stuff[i].end());
        reverse(stuff[i].begin(), stuff[i].end());
        for(int &x : stuff[i]){
            x /= i;
            int cnt = 0;
            for(int d : factors[x])
                cnt += mu[d]*occur[d];
            while(cnt){
                int y = st.top(); st.pop();
                if(__gcd(x, y) == 1)
                    ans = max(ans, 1ll*x*y*i), cnt--;
                for(int d : factors[y])
                    occur[d]--;
            }
            for(int d : factors[x])
                occur[d]++;
            st.push(x);
        }
        while(st.size()){
            int y = st.top(); st.pop();
            for(int d : factors[y])
                occur[d]--;
        }
    }
    cout << ans << endl;
}