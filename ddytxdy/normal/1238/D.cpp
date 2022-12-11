#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,nxt[N],p[2],ans;char s[N];
int main(){
    scanf("%d%s",&n,s+1);
    p[0]=p[1]=0;
    for(int i=1;i<=n;i++)nxt[i]=p[s[i]-'A'],p[s[i]-'A']=i;
    for(int i=1;i<=n;i++)ans+=i-nxt[i];
    p[0]=p[1]=n+1;
    for(int i=n;i;i--)nxt[i]=p[s[i]-'A'],p[s[i]-'A']=i;
    for(int i=1;i<=n;i++)ans+=nxt[i]-i;
    ans-=n;
    for(int i=1;i<n;i++)if(s[i+1]!=s[i])ans--;
    cout<<1ll*n*(n+1)/2-ans;
    return 0;
}