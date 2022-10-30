#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
using namespace std;
const int N=1e6+6,INF=1e9,P=998244353;
int tag[N];
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int n=read(),k=read(),t=0; long long s=0;
    for (int i=1;i<=n;++i){
        int p=read();
        if (p>=n-k+1) s+=p,tag[++t]=i;
    }
    cout<<s<<" ";
    sort(tag+1,tag+1+t);
    int ans=1;
    for (int i=2;i<=t;++i) ans=1LL*ans*(tag[i]-tag[i-1])%P;
    cout<<ans<<endl;
}