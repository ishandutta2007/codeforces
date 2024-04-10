#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100010
vector<int>e[SIZE];
int used[SIZE],n,cnt,ha[SIZE];
double dp[SIZE],an;
int dfs(int x){
    used[x]=1;
    ha[cnt]++;
    for(int i=0;i<e[x].size();i++){
        if(!used[e[x][i]]){
            cnt++;
            dfs(e[x][i]);
            cnt--;
        }
    }
}
int main(){
    int i,j,k;
    cin>>n;
    dp[1]=1;
    for(i=2;i<=n;i++)dp[i]=1./i;
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    cnt++;
    dfs(1);
    for(i=1;i<=n;i++)an+=ha[i]*dp[i];
    printf("%.12lf\n",an);
    return 0;
}