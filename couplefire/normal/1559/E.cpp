#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 100005;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int mu[N], ans; vector<int> primes;
bool flag[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
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
    
    int n, m; cin >> n >> m;
    vector<array<int, 2>> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i][0] >> arr[i][1];
    for(int i = 1; i<=m; ++i){
        vector<array<int, 2>> tmp = arr;
        for(int j = 0; j<n; ++j)
            tmp[j][0] = (tmp[j][0]-1)/i+1, tmp[j][1] = (tmp[j][1])/i;
        bool bad = 0;
        for(int j = 0; j<n; ++j)
            if(tmp[j][0]>tmp[j][1]){bad=1; break;}
        if(bad) continue;
        int tm = m/i;
        vector<int> dp1(tm+1, 1), dp2(tm+1, 0);
        for(int j = 0; j<n; ++j){
            fill(dp2.begin(), dp2.end(), 0);
            for(int k = 0; k<=tm; ++k){
                int l = k-tmp[j][1], r = k-tmp[j][0];
                if(r<0) continue;
                l = max(l, 0); r = min(r, tm);
                if(l==0) dp2[k] = dp1[r];
                else dp2[k] = sub(dp1[r], dp1[l-1]);
            }
            for(int k = 1; k<=tm; ++k)
                inc(dp2[k], dp2[k-1]);
            swap(dp1, dp2);
        }
        inc(ans, mul((mu[i]+MOD)%MOD, dp1[tm]));
    }
    cout << ans << '\n';
}