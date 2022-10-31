#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6,P=1e9+7;
int l[N],p[N];
ll s[N];
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int n=read(),m=read();
    rep(i,1,m) l[i]=read();
    rep(i,1,m) s[i]=s[i-1]+l[i];
    if (s[m]<n){ cout<<-1<<endl; return 0; }
    int lst=n+1;
    per(i,m,1){
        int le=max(i,lst-l[i]),r=min(s[i-1]+1,(ll)min(n-l[i]+1,lst-1));
        if (le>r){ cout<<-1<<endl; return 0; }
        lst=p[i]=r;
    }
    rep(i,1,m) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}