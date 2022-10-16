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
const int MAXN=1e5+10,MAXM=6,MAXK=MAXN*(1<<5)+10,INF=2e9+10;
int n,m,tot,val[MAXK],ans;
array<int,6>a[MAXN];
map<int,int>ch[MAXK];
int P(int x){if(odd(x))return -1;else return 1;}
void add(const array<int,6>& a,int u,int r,int c){
    if(r>m){val[u]+=c;return;}
    add(a,u,r+1,c);
    if(ch[u].find(a[r])==ch[u].end())ch[u][a[r]]=++tot,val[tot]=0,ch[tot].clear();
    add(a,ch[u][a[r]],r+1,c);
}
int qry(const array<int,6>& a,int u,int r,int sum){
    if(r>m){return P(sum)*val[u];}
    int ret=0;
    ret+=qry(a,u,r+1,sum);
    if(ch[u].find(a[r])!=ch[u].end())ret+=qry(a,ch[u][a[r]],r+1,sum+1);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n){
        rep(j,1,m)cin>>a[i][j];
        cin>>a[i][0];
        sort(a[i].begin()+1,a[i].begin()+1+m);
    }
    sort(a+1,a+1+n);
    int l,r=2;
    add(a[1],0,1,1);
    while(r<=n&&!qry(a[r],0,1,0)){
        add(a[r],0,1,1);
        r++;
    }
    if(r>n){cout<<-1<<endl;return 0;}
    ans=INF;
    l=r-1;
    for(;r<=n&&l>=1;r++){
        while(l>=1&&qry(a[r],0,1,0)){
            add(a[l],0,1,-1);
            l--;
        }
        ans=min(ans,a[l+1][0]+a[r][0]);
    }
    cout<<ans<<endl;
    return 0;
}