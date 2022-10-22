#include<bits/stdc++.h>
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=100010;
int i,j,k,n,m,T,a[maxn],b[maxn],c[maxn],is[maxn];
vector<int>V[maxn];
int main(){
    cin>>T;
    while(T--){
        k=0;
        scanf("%d",&n);
        int now,cnt=0;
        for(i=0;i<=n+1;i++)is[i]=c[i]=0,V[i].clear();
        for(i=1;i<=n;i++)scanf("%d",&a[i]),is[a[i]]=1,V[a[i]].push_back(i);
        for(i=1;i<=n;i++)if(a[i]>i)k=max(k,i);
        if(is[0])now=0;else now=n+1;
        while(1){
            // cerr<<"now="<<now<<endl;
            int u=-1;
            for(int i=0;i<V[now].size();i++)
                if(!is[V[now][i]])c[++cnt]=V[now][i];
            for(int i=0;i<V[now].size();i++)
                if(is[V[now][i]]){
                    c[++cnt]=V[now][i];
                    u=c[cnt];
                }
            if(u<0)break;else now=u;
        }
        printf("%d\n",k);
        for(i=1;i<=n;i++)printf("%d ",c[i]);puts("");
    }
}