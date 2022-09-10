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
#define SIZE 55555
vector<int>e[SIZE];
int k;
long long an;
bool used[SIZE];
void dfs(int x,int d[501]){
    used[x]=1;
    int d2[501];
    int i,j;
    for(i=0;i<=k;i++)d[i]=0;
    d[0]=1;
    for(i=0;i<e[x].size();i++){
        if(used[e[x][i]]==0){
            dfs(e[x][i],d2);
            for(j=k;j>0;j--){
                d2[j]=d2[j-1];
                an+=(long long)d2[j]*d[k-j];
            }
            for(j=1;j<=k;j++)d[j]+=d2[j];
        }
    }
}
int main(){
    int i,j,n;
    cin>>n>>k;
    if(n==1){
        puts("0");
        return 0;
    }
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    int d[501]={};
    dfs(1,d);
    cout<<an<<endl;
    return 0;
}