#include<bits/stdc++.h>
using namespace std;
int n,m,f[223456],x[233333],y[233333],c[233333],p[233333],d[233333];
unordered_map<int,int>M[233333];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
    int _; cin>>_; while(_--){
		scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>y[i]) swap(x[i],y[i]);
            M[x[i]][y[i]]++;
        }
        retry:
        for(int i=1;i<=m;++i) p[i]=i,c[i]=0;
        for(int i=1;i<=m;++i) swap(p[rand()%m+1],p[rand()%m+1]);
        for(int i=1;i<=n;++i) f[i]=i;
        for(int i=1;i<=m;++i)if(M[x[i]][y[i]]>1){
            f[find(x[i])]=find(y[i]);
            c[i]=1;
        }
        for(int i=1;i<=m;++i)if(!c[p[i]]){
            int u=p[i];
            if(find(x[u])!=find(y[u])) f[find(x[u])]=find(y[u]), c[u]=1;
        }
        for(int i=1;i<=m;++i) if(!c[i]) d[x[i]]++,d[y[i]]++;
        int z=0;
        for(int i=1;i<=n;++i){z+=d[i]==2; d[i]=0;}
        if(z==3) goto retry;
        for(int i=1;i<=m;++i)putchar('0'+c[i]);
        puts("");
        for(int i=1;i<=n;++i) M[i].clear();
	}
}