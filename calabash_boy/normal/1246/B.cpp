#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long ll;
bool used[maxn];
vector<int> prime;
int low[maxn];
pair<int,int> LOW[maxn];
ll powv[maxn][101];
void sieve(int size){
    //f:multiplicative function;
    assert(size < maxn);
    for (int i=2;i<=size;i++){
        if (!used[i]){
            prime.push_back(i);
            low[i] = i;
            LOW[i] = make_pair(i,1);
        }
        for (int j = 0;j < prime.size();j++){
            ll nxt = 1ll * i * prime[j];
            if (nxt > size)break;
            used[nxt] = 1;
            if (i % prime[j]){
                low[nxt] = prime[j];
                LOW[nxt] = make_pair(prime[j],1);
            }else{
                low[nxt] = prime[j] * low[i];
                LOW[nxt] = LOW[i];
                LOW[nxt].second ++;
                break;
            }
        }
    }
    memset(powv,-1,sizeof powv);
    for (int i=1;i<maxn;i++){
        powv[i][0] = 1;
        for (int j=1;j<=100;j++){
            powv[i][j] = powv[i][j-1] * i;
            if (powv[i][j] >100000){
                powv[i][j] = -1;
                break;
            }
        }
    }
}
int cnt[maxn];
int main(){
    sieve(1e5);
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        int val = 1;
        int tar = 1;
        while (x != 1){
            pair<int,int> tmp = LOW[x];
            if (tmp.second % k){
                val *= powv[tmp.first][tmp.second %k];
                if (tar != -1){
                    tar *= powv[tmp.first][k - tmp.second % k];
                    if (tar < 0 or tar > 100000)tar = -1;
                }
            }
            x /= low[x];
        }
      //  cerr<<val<<" "<<tar<<"" <<cnt[tar]<<endl;
        if (tar != -1)ans += cnt[tar];
        cnt[val] ++;
    }
    cout<<ans<<endl;
    return 0;
}