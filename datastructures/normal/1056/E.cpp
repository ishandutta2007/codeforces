#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define base 30
#define mod 998244353
using namespace std;
char x[1000005],a[1000005];
int n,m,ans,pw[1000005],hs[1000005],num0,num1;
inline int ask(int l,int r){
    return ((hs[r]-hs[l-1]*pw[r-l+1])%mod+mod)%mod;
}
signed main(){
    scanf("%s%s",x+1,a+1);
    n=strlen(a+1),m=strlen(x+1);
    pw[0]=1;
    for (int i=1;i<=n;i++)pw[i]=pw[i-1]*base,pw[i]%=mod;
    hs[0]=1;
    for (int i=1;i<=n;i++)hs[i]=hs[i-1]*base+a[i]-'a'+1,hs[i]%=mod;
    for (int i=1;i<=m;i++){
        if (x[i]=='1')num1++;
        else num0++;
    }
    for (int len0=1;len0<=n;len0++){
        if (len0*num0>=n)continue;
        if ((n-len0*num0)%num1!=0)continue;
        int len1=(n-len0*num0)/num1;
        int now=1,flag=1,hash0=-1,hash1=-1;
        for (int i=1;i<=m;i++){
            if (x[i]=='0'){
                if (hash0==-1)hash0=ask(now,now+len0-1);
                else if (hash0!=ask(now,now+len0-1))flag=0;
                now+=len0;
            }
            else if (x[i]=='1'){
                if (hash1==-1)hash1=ask(now,now+len1-1);
                else if (hash1!=ask(now,now+len1-1))flag=0;
                now+=len1;
            }
        }
        if (hash0==hash1)flag=0;
        if (flag!=0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}