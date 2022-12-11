#include<bits/stdc++.h>
using namespace std;
int n,m,k,top;
long long d[21][123456],K[123456],B[123456];
vector<int>v[234567],w[234567];
#define pa pair<long long,int>
priority_queue<pa,vector<pa>,greater<pa> >q;
double meet(int k1,long long b1,int k2,long long b2){return 1.*(b2-b1)/(k2-k1);}
void Dijk(int T){
    #define mp make_pair
    for(int i=1;i<=n;++i) if(d[T][i]<1e12) q.push(mp(d[T][i],i));
    while(!q.empty()){
        long long D=q.top().first; int x=q.top().second; q.pop();
        if(D!=d[T][x]) continue;
        for(unsigned int i=0;i<v[x].size();++i) if(D+w[x][i]<d[T][v[x][i]]) q.push(mp(d[T][v[x][i]]=D+w[x][i],v[x][i])); 
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i) {
        int a,b,x; scanf("%d%d%d",&a,&b,&x);
        #define pb push_back
        v[a].pb(b); v[b].pb(a);
        w[a].pb(x); w[b].pb(x);
    }
    for(int i=2;i<=n;++i) d[0][i]=1e18;
    #define mp make_pair
    q.push(mp(0ll,1));
    while(!q.empty()){
        long long D=q.top().first; int x=q.top().second; q.pop();
        if(D!=d[0][x]) continue;
        for(unsigned int i=0;i<v[x].size();++i) if(D+w[x][i]<d[0][v[x][i]]) q.push(mp(d[0][v[x][i]]=D+w[x][i],v[x][i])); 
    }
    for(int t=0;t<k;++t){
        //cerr<<t<<endl;
        top=0;
        for(int i=1;i<=n;++i){
            //if(top>=2&&B[top]-K[top]*i>=B[top-1]-K[top-1]*i) top--;
            //if(top>=1)d[t+1][i]=min(d[t+1][i],B[top]-K[top]*1ll*i*i);
            //top++; B[top]=d[t][i]+1ll*i*i; K[top]=i<<1;
            int kk=i<<1; long long bb=d[t][i]+1ll*i*i;
            while(top>=2&&meet(kk,bb,K[top],B[top])<=meet(kk,bb,K[top-1],B[top-1])) top--;
            top++; B[top]=d[t][i]+1ll*i*i; K[top]=i<<1;
        }
        int p=1;
        for(int i=1;i<=n;++i){
            while(p<top&&B[p]-K[p]*i>=B[p+1]-K[p+1]*i) p++;
            d[t+1][i]=B[p]-K[p]*i+1ll*i*i;
        }
        Dijk(t+1);
    }
    for(int i=1;i<=n;++i) printf("%lld ",d[k][i]);
}