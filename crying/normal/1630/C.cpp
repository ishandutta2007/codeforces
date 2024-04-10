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
int n,a[MAXN];
int L[MAXN],R[MAXN];
pi x[MAXN];
int cnt,ans;
void solve(int u,int tag){
    if(u>cnt)return;
    if(tag)ans+=x[u].se-x[u].fr-1;
    int rp=u,maxn=0,maxpos=0;
    while(rp<cnt){
        if(x[rp+1].fr>x[u].se)break;
        if(x[rp+1].se>maxn){
            maxn=x[rp+1].se;
            maxpos=rp+1;
        }
        rp++;
    }
    if(maxpos>u && maxn>x[u].se){
        ans+=maxn-x[u].se-1,
        solve(maxpos,0);
    }else{
        solve(rp+1,1);
    }
}
int main(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n){
        if(!L[a[i]])L[a[i]]=i;
        else R[a[i]]=i;
    }
    rep(i,1,n){
        if(L[i]<R[i]){
            x[++cnt]=mp(L[i],R[i]);
        }
    }
    sort(x+1,x+1+cnt);
    solve(1,1);
    printf("%d",ans);
    return 0;
}