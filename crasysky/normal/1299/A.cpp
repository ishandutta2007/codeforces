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
int a[N],l[N],r[N];
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,n) l[i]=l[i-1]|a[i];
    per(i,n,1) r[i]=r[i+1]|a[i];
    int ans=-1,w=0;
    rep(i,1,n){
        int t=l[i-1]|r[i+1];
        if ((a[i]^(a[i]&t))>ans) ans=a[i]^(a[i]&t),w=i;
    }
    cout<<a[w]<<" ";
    rep(i,1,n) if (i!=w) cout<<a[i]<<" ";
    return 0;
}