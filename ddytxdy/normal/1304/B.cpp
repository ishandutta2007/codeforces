#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=120;
int n,m,cnt[N],L,mx,id;char s[N][N],ans[N*N];bool vis[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)if(!vis[i])
        for(int j=i+1;j<=n;j++)if(!vis[j]){
            int len=strlen(s[i]+1);bool fl=1;
            for(int k=1;k<=len;k++)
                if(s[i][k]!=s[j][len-k+1]){fl=0;break;}
            if(fl){
                vis[i]=vis[j]=1;
                for(int k=1;k<=len;k++)ans[++L]=s[i][k];
            }
        }
    for(int i=1;i<=n;i++)if(!vis[i]){
        int len=strlen(s[i]+1);bool fl=1;
        for(int k=1;k<=len;k++)
            if(s[i][k]!=s[i][len-k+1]){fl=0;break;}
        if(fl&&len>mx)mx=len,id=i;
    }
    printf("%d\n",2*L+mx);
    printf("%s",ans+1);if(id)printf("%s",s[id]+1);
    reverse(ans+1,ans+L+1);printf("%s",ans+1);
    return 0;
}