#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,k,l[N],r[N];char s[N],ans[N];bool flag[N];
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    s[0]=s[n];s[n+1]=s[1];
    for(int i=1;i<=n;i++)if(s[i]==s[i-1]||s[i]==s[i+1])flag[i]=1;
    for(int i=1;i<=n;i++)if(flag[i])l[i]=i;else l[i]=l[i-1];
    for(int i=n;i;i--)if(flag[i])r[i]=i;else r[i]=r[i+1];
    if(!l[n]){
        for(int i=1;i<=n;i++)ans[i]=k&1?s[i-1]:s[i];
        printf("%s",ans+1);return 0;
    }
    for(int i=1;!l[i];i++)l[i]=l[n];
    for(int i=n;!r[i];i--)r[i]=r[1];
    for(int i=1;i<=n;i++){
        if(flag[i])ans[i]=s[i];
        else{
            int dl=(i-l[i]+n)%n,dr=(r[i]-i+n)%n,mn=min(dl,dr);
            if(mn<=k)ans[i]=dl<dr?s[l[i]]:s[r[i]];
            else ans[i]=k&1?s[i-1]:s[i];
        }
    }
    printf("%s",ans+1);
    return 0;
}