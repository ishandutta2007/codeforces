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
const int MAXN=20;
int T;
ll a,s;
ll aa[MAXN],ss[MAXN],b[MAXN*2],tot;

void solve(){
    cin>>a>>s;
    ll na=a,ns=s;
    int r=0,la=0,ls=0;
    tot=0;
    rep(i,0,19){
        aa[i]=na%10;ss[i]=ns%10;
        na/=10,ns/=10;
        if(aa[i])la=i;
        if(ss[i])ls=i;
    }
    rep(i,0,la){
        if(r>ls){printf("-1\n");return;}
        if(aa[i]<=ss[r]){b[++tot]=ss[r]-aa[i];r++;continue;}
        if(r+1>ls || ss[r+1]!=1){printf("-1\n");return;}
        b[++tot]=(ss[r]+10-aa[i]);
        r+=2;
    }
    rep(i,r,ls)b[++tot]=ss[i];
    while(tot>1&&b[tot]==0)tot--;
    per(i,tot,1)printf("%lld",b[i]);
    printf("\n");
}
int main(){
    cin>>T;
    while(T--)solve();
    
    return 0;
}
/*
1
1 11
*/