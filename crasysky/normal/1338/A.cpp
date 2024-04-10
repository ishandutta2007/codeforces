#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e5+5,P=1e9+7;
int a[N];
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
signed main(){
    int T=read();
    while (T--){
        int n=read(),mx,ans=0;
        rep(i,1,n){
            a[i]=read();
            if (i==1) mx=a[i];
            else{
                if (a[i]>mx) mx=a[i];
                else{
                    int t=mx-a[i],s=0;
                    while (t) t>>=1,++s;
                    ans=max(ans,s);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}