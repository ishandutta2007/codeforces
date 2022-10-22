    #include<iostream>
    #include<cstring>
    #include<cassert>
    #include<cmath>
    #include<map>
    #include<set>
    #include<queue>
    #include<stack>
    #include<vector>
    #include<cstdio>
    #include<time.h>
    #include<algorithm>
    using namespace std;
    #define REP(i,x,y) for(int i=x;i<=y;i++)
    #define rep(i,n) REP(i,1,n)
    #define rep0(i,n) REP(i,0,n-1)
    #define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
    #define ll long long
    #define db double
    const int N=5e5+7;
    const int INF=1e9+7;
    int U[N],V[N],pos[N],g[N];
    bool p[N],d[N];
    int T,n,m,num;
    struct edge{int v,next;}e[N*2];
    void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
    void dcr(int x){d[x]=1; repG(i,x)g[i/2+1]--;}
     
    int main(){
    	scanf("%d",&T);
    	while(T--){
    		scanf("%d%d",&n,&m);
    		num=0;
    		rep(i,m)scanf("%d%d",&U[i],&V[i]),g[i]=2;
    		rep(i,3*n)pos[i]=-1,d[i]=0;
    		rep(i,m)p[i]=0;
    		rep(i,m)add(U[i],V[i]),add(V[i],U[i]);
    		int sm=0;
    		rep(i,m){
    			if(g[i]==2){
    				sm++;
    				p[i]=1;
    				dcr(U[i]);
    				dcr(V[i]);
    			}
    		}
    		if(sm>=n){
    			int u=0;
    			puts("Matching");
    			rep(i,m){
    				if(p[i]){
    					u++;
    					printf("%d ",i);
    					if(u==n)break;
    				}
    			}
    			puts("");
    		}
    		else{
    			int u=0;
    			puts("IndSet");
    			rep(i,n*3){
    				if(!d[i]){
    					printf("%d ",i);
    					u++;
    					if(u==n)break;
    				}
    			}
    			puts("");
    		}
    	}
    	return 0;
    }