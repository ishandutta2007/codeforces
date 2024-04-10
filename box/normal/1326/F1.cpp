// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

long long re[14][1<<14][1<<6];
bool vis[14][14];
long long ans[1<<14];
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    rep(i,n){
        string s;cin>>s;
        rep(j,n)vis[i][j]=(s[j]=='1');
    }
    rep(i,n)re[i][1<<i][0]=1;
    int h=(n+1)/2;
    rep(i,1<<n){
        if(!i) continue;
        if(__builtin_popcount(i)+1>h)continue;
        int pos=__builtin_popcount(i)-1;
        assert(pos<=(n-1)/2-1);
        rep(u,n){
            if(!(i&(1<<u)))continue;
            rep(j,1<<pos)
                rep(v,n){
                    if(i&(1<<v))continue;
                    re[v][i|(1<<v)][j|((vis[u][v])<<pos)]+=re[u][i][j];
                }
        }
    }
    int A=(n-1)/2;
    int B=n-1-A-1;
    int K=A+1;
    vector<int>Brev(1<<B);
    rep(i,1<<B){
        int j=0;
        rep(k,B){
            int c=!!(i&(1<<k));
            j|=(c<<(B-k-1));
        }
        Brev[i]=j;
    }
    vector<int>mk;
    rep(i,1<<n)if(__builtin_popcount(i)==K)mk.push_back(i);
    for(int i:mk){
        int j=((1<<n)-1)^i;
        rep(u,n){
            if(!(i&(1<<u)))continue;
            rep(v,n){
                if(!(j&(1<<v)))continue;
                rep(a,1<<A)rep(b,1<<B){
                    int fm=a;
                    fm|=(vis[u][v]<<A);
                    fm|=(Brev[b]<<(A+1));
                    ans[fm]+=re[u][i][a]*re[v][j][b];
                }
            }
        }
    }
    rep(i,1<<(n-1))cout<<ans[i]<<" \n"[i==(1<<(n-1))-1];
}