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
const int N=1e6+6;
int dp[102];
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int T=read();
    while (T--){
        int n=read(),P=read(),ans=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        rep(i,0,30){
            rep(j,i+1,30)
                if ((1<<j-1)<=n)
                    dp[j]=(dp[j]+(ll)dp[i]*(min((1<<j)-1,n)-(1<<j-1)+1))%P;
                else break;
            if (i) ans=(ans+dp[i])%P;
        }
        cout<<ans<<endl;
    }
    return 0;
}