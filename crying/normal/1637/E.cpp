#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10;
int t,n,m;
map<pi,bool>f;
map<int,int>cnt;
map<int,vector<int> >arr;
int a[MAXN],b[MAXN],tot;
vector<int>tmp[MAXN];
ll ans;
void solve(){
    ans=0;tot=0;
    cin>>n>>m;f.clear();cnt.clear();arr.clear();
    rep(i,1,n)cin>>a[i],cnt[a[i]]++;
    rep(i,1,m){
        int x,y;cin>>x>>y;
        f[mp(x,y)]=f[mp(y,x)]=1;
    }
    for(auto it:cnt){arr[it.se].pb(it.fr);b[++tot]=it.se;}
    sort(b+1,b+1+tot);
    tot=unique(b+1,b+1+tot)-b-1;
    rep(i,1,tot)tmp[i]=arr[b[i]],sort(tmp[i].begin(),tmp[i].end(),greater<int>());
    rep(i,1,tot)rep(j,1,i){
        if(tmp[i].empty() || tmp[j].empty())continue;
        for(auto x:tmp[i]){
            if(f[mp(x,tmp[j][0])]==0 && x!=tmp[j][0]){
                int y=tmp[j][0];
                ans=max(ans,1ll*(cnt[x]+cnt[y])*(x+y));
                break;
            }
            int sz=tmp[j].size();
            rep(idx,1,sz-1){
                int y=tmp[j][idx];
                if(f[mp(x,y)]==0 && x!=y){
                    ans=max(ans,1ll*(cnt[x]+cnt[y])*(x+y));
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)solve();

    return 0;
}