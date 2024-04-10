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
const int MAXN=2e5+10;
int T,n,a[MAXN];
ll ans[MAXN],f[MAXN],cnt[MAXN];
deque<int>q;
void solve(){
    cin>>n;
    rep(i,0,n)cnt[i]=0,f[i]=-1,ans[i]=-1;
    rep(i,1,n){cin>>a[i];cnt[a[i]]++;}
    while(q.size())q.pop_back();
    if(cnt[0]>=1){f[0]=0;rep(i,1,cnt[0]-1)q.push_back(0);}
    rep(i,1,n){
        if(f[i-1]==-1)break;
        if(cnt[i]){
            f[i]=f[i-1];
            rep(j,1,cnt[i]-1)q.push_back(i);
        }else{
            if(q.empty())continue;
            int pos=q.back();
            f[i]=f[i-1]+i-pos;
            q.pop_back();
        }
    }
    printf("%lld ",cnt[0]);
    rep(i,1,n){
        if(f[i-1]==-1)printf("-1 ");
        else printf("%lld ",f[i-1]+cnt[i]);
    }
    printf("\n");
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}