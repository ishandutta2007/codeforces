#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,A[300010],Ai[300010],dfn[300010],totn,dfl[300010],dfli[300010],totl,F[300010],dep[300010];
vector<int> T[300010];
void dfs(int x,int fa){
    dfn[x]=++totn;F[x]=fa;
    dep[x]=dep[fa]+1;
    vector<pair<int,int> > vec; 
    for(auto to:T[x]){
        if(to==fa) continue;
        vec.push_back(make_pair(A[to],to));
    }
    sort(vec.begin(),vec.end());
    for(auto to:vec) dfs(to.second,x);
    dfl[x]=++totl;dfli[totl]=x;
    // printf("%d %d %d\n",x,dfn[x],dfl[x]);
}
int tot2;
void dfs2(int x,int fa,int minn){
    if(A[x]<minn) return;
    tot2++;
    // printf("DFS %d %d\n",x,tot2);
    if(A[x]!=tot2){puts("NO");exit(0);}
    vector<pair<int,int> > vec; 
    for(auto to:T[x]){
        if(to==fa) continue;
        vec.push_back(make_pair(A[to],to));
        // printf("%d\n",to);
    }
    sort(vec.begin(),vec.end());
    for(auto to:vec) dfs2(to.second,x,minn);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i]),Ai[A[i]]=i;
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        T[x].push_back(y);
        T[y].push_back(x);
    }dfs(1,0);int t=0,tv,t2;long long ans=0;
    for(int i=1;i<=n;i++){
        if(Ai[i]!=dfli[i]){t=Ai[i];tv=i;t2=dfli[i];break;}
        ans+=dep[Ai[i]]-1;
    }
    // printf("%d %d\n",t,tv);
    if(!t){
        printf("YES\n%lld\n",ans);
        for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
        return 0;
    }
    bool pd=1;
    while(1){
        t2=F[t2];
        if(t2==t){pd=0;break;}
        if(t2==1) break;
    }
    if(pd){puts("NO");return 0;}
    while(t!=1){swap(A[t],A[F[t]]);t=F[t];ans++;}
    // for(int i=1;i<=n;i++) printf("%d ",A[i]);
    tot2=tv-1;dfs2(1,0,tv);
    printf("YES\n%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}