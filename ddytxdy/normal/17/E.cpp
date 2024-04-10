#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e6+50,mod=51123987;
int n,ver[N],edge[N],nxt[N],head[N],tot,fail[N],num[N],len[N],cnt,lst,a[N],b[N];char s[N];LL sum,ans;
void init(){fail[1]=fail[0]=cnt=1;len[1]=-1;}
void add(int x,int y,int z){ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;}
int go(int x,int z){for(int i=head[x];i;i=nxt[i])if(edge[i]==z)return ver[i];return 0;}
void extend(int i){
    int c=s[i]-'0',p=lst,x;
    while(s[i-len[p]-1]!=s[i])p=fail[p];
    if(x=go(p,c)){lst=x;return;}
    x=++cnt;int k=fail[p];
    while(s[i-len[k]-1]!=s[i])k=fail[k];
    fail[x]=go(k,c);len[x]=len[p]+2;
    add(p,x,c);lst=x;num[x]=num[fail[x]]+1;
}
int main(){
    // freopen("data.txt","r",stdin);
    // freopen("my.txt","w",stdout);
    scanf("%d%s",&n,s+1);init();
    for(int i=1;i<=n;i++)extend(i),a[i]=num[lst];
    memset(head,0,sizeof(head));tot=0;
    init();lst=0;
    reverse(s+1,s+n+1);
    for(int i=1;i<=n;i++)extend(i),b[n-i+1]=num[lst];
    for(int i=n;i;i--)ans-=1ll*a[i]*sum%mod,(sum+=b[i])%=mod;
    (ans+=sum*(sum-1)/2)%=mod;
    cout<<(ans+mod)%mod;
    return 0;
}