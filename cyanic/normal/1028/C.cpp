#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
    int f=0;x=0;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(f)x=-x;
}

const int N=200005,inf=1e9+9;
struct rec{
    int l,r,d,u;
} pre[N],suf[N],a[N];
int n,X1,Y1,X2,Y2;

rec merge(rec a,rec b){
    rec res;
    res.l=max(a.l,b.l);
    res.r=min(a.r,b.r);
    res.d=max(a.d,b.d);
    res.u=min(a.u,b.u);
    return res;
}

int main(){
    read(n);
    rep(i,1,n){
        read(X1),read(Y1);
        read(X2),read(Y2);
        a[i].l=X1,a[i].r=X2;
        a[i].d=Y1,a[i].u=Y2;
    }
    pre[0]=suf[n+1]=(rec){-inf,inf,-inf,inf};
    rep(i,1,n) pre[i]=merge(pre[i-1],a[i]);
    per(i,n,1) suf[i]=merge(suf[i+1],a[i]);
    rep(i,1,n){
        rec now=merge(pre[i-1],suf[i+1]);
        if(now.l<=now.r&&now.d<=now.u){
            printf("%d %d\n",now.l,now.d);
            return 0;
        }
    }
    return 0;
}