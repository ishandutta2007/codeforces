#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
int book[500005];
int n,a[500005],u[500005],v[500005],first[500005],nxt[500005];
int tail,q[500005];
ll ans[500005];
vector <int>c[500005];
inline int read(){
    register int x=0;
    register char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline int dfs(register int now){
    register int ans=1;
    book[now]=2;
    for (register int i=first[now];i;i=nxt[i])
        if (book[v[i]]==1)ans+=dfs(v[i]);
    return ans;
}
signed main(){
    cin>>n;
    for (register int i=1;i<=n;i++)a[i]=read();
    for (register int i=1;i<n;i++){
        u[i]=read(),v[i]=read();
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    for (register int i=1;i<=n;i++){
        for (register int j=1;j*j<=a[i];j++){
            if (a[i]%j!=0)continue;
            c[j].push_back(i);
            if (a[i]/j!=j)c[a[i]/j].push_back(i);
        }
    }
    for (register int i=1;i<=200000;i++){
        tail=0;
        for (register int j=0,len=c[i].size();j<len;j++)
            q[++tail]=c[i][j],book[c[i][j]]=1;
        for (register int j=1;j<=tail;j++){
            if (book[q[j]]==1){
                register int now=dfs(q[j]);
                ans[i]+=(now+1ll)*now/2ll;
            }
        }
        for (register int j=1;j<=tail;j++)book[q[j]]=0;
    }
    for (register int i=200000;i>=1;i--){
        for (register int j=i*2;j<=200000;j+=i)
            ans[i]-=ans[j];
    }
    for (register int i=1;i<=200000;i++){
        if (ans[i]!=0)printf("%d %lld\n",i,ans[i]);
    }
    return 0;
}