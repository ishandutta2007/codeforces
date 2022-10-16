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
const int MAXN=1e5+10;
int T,n,m,maxn[MAXN];
vector<int>p[MAXN];
int check(int mid){
    if(n-1>=m)return 1;
    rep(i,1,m){
        int cnt=0;
        rep(j,1,n)if(p[i][j]>=mid)cnt++;
        if(cnt>=2)return 1;
    }
    return 0;
}
void solve(){
    cin>>m>>n;
    rep(i,1,n)maxn[i]=0;
    rep(i,1,m){
        p[i].clear();p[i].push_back(0);
        rep(j,1,n){
            int tmp;cin>>tmp;p[i].push_back(tmp);
            maxn[j]=max(maxn[j],tmp);
        }
    }
    int lim=2e9;rep(i,1,n)lim=min(lim,maxn[i]);
    int l=1,r=lim,ret=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ret=mid;l=mid+1;
        }else r=mid-1;
    }
    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}