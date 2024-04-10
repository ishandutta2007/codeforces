#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int n,m,k,a[N],b[N],c[N],mx[N],f[N],s[N],ans=-1e9;
vector<int>v[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);s[0]=k;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+b[i];
    for(int i=1;i<=n;i++)mx[i]=i;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        mx[y]=max(mx[y],x);
    }
    for(int i=1;i<=n;i++)v[mx[i]].push_back(i);
    memset(f,0xcf,sizeof(f));f[k]=0;
    for(int i=1;i<=n;i++){
        for(int j=s[i-1];j>=a[i];j--)f[j+b[i]]=f[j];
        for(int j=0;j<a[i]+b[i];j++)f[j]=-1e9;
        for(int j=0;j<v[i].size();j++)
            for(int l=0;l<s[i];l++)f[l]=max(f[l],f[l+1]+c[v[i][j]]);
        
    }
    for(int i=0;i<=s[n];i++)ans=max(ans,f[i]);
    printf("%d\n",ans<0?-1:ans);
    return 0;
}