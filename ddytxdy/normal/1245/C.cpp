#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,mod=1e9+7;
char s[N];int n,f[N],ans=1;char la;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    f[1]=1;f[2]=2;
    for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1,p;i<=n;i++){
        if(s[i]=='m'||s[i]=='w')puts("0"),exit(0);
        if(s[i]!='n'&&s[i]!='u')continue;
        int j=i;
        while(j<n&&s[j+1]==s[i])j++;
        ans=1ll*ans*f[j-i+1]%mod;
        i=j;
    }
    printf("%d\n",ans);
    return 0;
}