/*
 * @Author: BilyHurington
 * @Date: 2021-07-01 10:33:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-01 11:17:04
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,q,a[100010];
// double p[5010];
struct Pair{int first,second;double p;}pr[5010];
bool cmp(Pair P1,Pair P2){
    if(P1.first!=P2.first) return P1.first<P2.first;
    return P1.second>P2.second;
}
stack<int> S;
vector<int> T[5010];
int Maxn[5010];
void dfs1(int x){
    // printf("%d %d %d\n",x,pr[x].first,pr[x].second);
    for(auto to:T[x]) dfs1(to);
    int pos=pr[x].first,j=0;
    while(1){
        // printf("%d\n",pos);
        while(j<T[x].size()&&pos==pr[T[x][j]].first){
            pos=pr[T[x][j]].second+1;
            j++;
        }
        if(pos>pr[x].second) break;
        Maxn[x]=max(Maxn[x],a[pos]);pos++;
    }
    // printf("%d %d\n",x,Maxn[x]);
}
double f[5010][10010],g[10010];int DPM;
void dfs2(int x){
    f[x][Maxn[x]]=1;
    for(int i=0;i<T[x].size();i++){
        dfs2(T[x][i]);
        double s0=0,s1=0,lst=0;
        memcpy(g,f[x],sizeof(f[x]));
        for(int j=0;j<=DPM;j++){
            s0+=g[j];s1+=f[T[x][i]][j];
            f[x][j]=s0*s1-lst;
            // printf("%lf %lf\n",s0,s1);
            lst=s0*s1;
        }
    }
    // for(int i=0;i<=DPM;i++) printf("%lf ",f[x][i]);puts("");
    double t=1;
    for(int i=DPM;i>Maxn[x];i--) t-=f[x][i];
    f[x][Maxn[x]]=t;
    if(!x) return;
    for(int i=DPM;i>=1;i--) f[x][i]=f[x][i-1]*pr[x].p+f[x][i]*(1-pr[x].p);
    f[x][0]=(1-pr[x].p)*f[x][0];
    // printf("%d %d %d %lf\n",x,pr[x].first,pr[x].second,pr[x]);
    // for(int i=0;i<=DPM;i++) printf("%lf ",f[x][i]);puts("");
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&q);
    int maxn=0;DPM=2*q;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
    }
    int D=maxn-q;
    for(int i=1;i<=n;i++) a[i]=max(0,a[i]-D);
    for(int i=1;i<=q;i++) scanf("%d %d %lf",&pr[i].first,&pr[i].second,&pr[i].p);
    sort(pr+1,pr+q+1,cmp);
    pr[0].first=1;pr[0].second=n;S.push(0);
    for(int i=1;i<=q;i++){
        while(pr[i].first>pr[S.top()].second) S.pop();
        T[S.top()].push_back(i);S.push(i);
    }dfs1(0);dfs2(0);
    double ans=0;
    for(int i=0;i<=2*q;i++) ans+=f[0][i]*i;
    printf("%.10lf",ans+D);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}