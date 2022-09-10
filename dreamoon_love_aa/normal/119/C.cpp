#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
struct data{
    long long a,b;
    int c,No;
    bool operator<(data X)const{
        return c<X.c||(c==X.c&&No<X.No);
    }
    bool in(long long x){
        return a<=x&&x<=b;
    }
}rr[50];
vector<int>e[5050];
long long a[50],b[50];
int c[50];
int back[5050][51];
long long dp[5050][51];
int get(int x,int t){
    return x*101+t-a[x];
}
long long dfs(int x,int n){
    if(dp[x][n]!=-1)return dp[x][n];
    if(n==1){
        dp[x][1]=x%101+a[x/101];
        return dp[x][1];
    }
    dp[x][n]=-2;
    for(int i=0;i<e[x].size();i++){
        long long tmp=dfs(e[x][i],n-1);
        if(tmp>=0&&tmp+a[x/101]+x%101>dp[x][n]){
            back[x][n]=e[x][i];
            dp[x][n]=tmp+a[x/101]+x%101;
        }
    }
    return dp[x][n];
}
void track(int x,int n){
    if(n==1){
        cout<<x/101+1<<" "<<x%101+a[x/101]<<endl;
        return;
    }
    track(back[x][n],n-1);
    cout<<x/101+1<<" "<<x%101+a[x/101]<<endl;
}
int main(){
    int n,m,i,j,k;
    long long an=-1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        rr[i]=(data){a[i],b[i],c[i],i};
    }
    sort(rr,rr+m);
    for(i=1;i<m;i++){
        for(j=0;rr[j].c<rr[i].c;j++){
            for(long long ii=rr[j].a;ii<=rr[j].b;ii++){
                if(rr[i].in(ii+k)){
                    e[get(rr[i].No,ii+k)].push_back(get(rr[j].No,ii));
                }
                if(rr[i].in(ii*k)){
                    e[get(rr[i].No,ii*k)].push_back(get(rr[j].No,ii));
                }
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    int res;
    for(i=0;i<m;i++){
        for(long long ii=a[i];ii<=b[i];ii++){
            int tmp=get(i,ii);
            for(j=1;j<=n;j++){
                if(dp[tmp][j]==-1)dfs(tmp,j);
            }
            if(dp[tmp][n]>an){
                res=tmp;
                an=dp[tmp][n];
            }            
        }
    }
    if(an!=-1){
        puts("YES");
        track(res,n);
    }
    else puts("NO");
    return 0;
}