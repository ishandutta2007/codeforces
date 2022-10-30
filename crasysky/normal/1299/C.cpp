#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+6;
int st[N];
ll a[N];
bool slope(int x,int x1,int x2){
    return (x1-x)*(a[x2]-a[x])>(x2-x)*(a[x1]-a[x]);
}
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read();
    rep(i,1,n) a[i]=a[i-1]+read();
    int tp=0; st[++tp]=0;
    rep(i,1,n){
        while (tp>1&&slope(i,st[tp],st[tp-1])) --tp;
        st[++tp]=i;
    }
    rep(i,1,tp)
        rep(j,st[i-1]+1,st[i])
            printf("%.8f\n",1.0*(a[st[i]]-a[st[i-1]])/(st[i]-st[i-1]));
    return 0;
}