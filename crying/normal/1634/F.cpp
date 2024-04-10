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
int n,q,mod,a[MAXN],b[MAXN],c[MAXN],f[MAXN],cnt;
void upd(int x,int val){
    if(x>n)return;
    if(!c[x])cnt--;
    c[x]+=val;
    if(c[x]>=mod)c[x]-=mod;
    if(!c[x])cnt++;
}
void Read(int& num){
    char ch;
    while((ch=getchar()) && !isdigit(ch));num=ch-'0';
    while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
int main(){
    Read(n);Read(q);Read(mod);
    rep(i,1,n)Read(a[i]);
    rep(i,1,n)Read(b[i]);
    rep(i,1,n)a[i]=(a[i]-b[i]+mod)%mod;
    c[1]=a[1];rep(i,2,n)c[i]=(0ll+a[i]-a[i-1]-a[i-2]+mod+mod)%mod;
    f[1]=1;rep(i,2,3e5+5)f[i]=(f[i-1]+f[i-2])%mod;
    rep(i,1,n)if(!c[i])cnt++;
    rep(i,1,q){
        char op;int l,r;scanf(" %c",&op);Read(l);Read(r);
        if(op=='A'){
            upd(l,1);
            upd(r+1,mod-f[r-l+2]);
            upd(r+2,mod-f[r-l+1]);
        }else{
            upd(l,mod-1);
            upd(r+1,f[r-l+2]);
            upd(r+2,f[r-l+1]);
        }
        if(cnt==n)puts("YES");
        else puts("NO");
    }
    return 0;
}