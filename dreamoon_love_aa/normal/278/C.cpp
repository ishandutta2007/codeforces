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
#define SIZE 111
vector<int>e[SIZE];
int d[SIZE],d_num[SIZE],used[SIZE];
int init(int n){for(int i=0;i<n;i++)d[i]=i,d_num[i]=1;}
int find(int x){return x!=d[x]?(d[x]=find(d[x])):x;}
bool uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return 0;
    if(d_num[x]<d_num[y]){d[x]=y;d_num[y]+=d_num[x];}
    else{d[y]=x;d_num[x]+=d_num[y];}
    return 1;
}
int main(){
    int i,j,k,n,m,zero=0;
    cin>>n>>m;
    init(m);
    for(i=0;i<n;i++){
        cin>>k;
        while(k--){
            cin>>j;
            j--;
            used[j]=1;
            e[i].pb(j);
        }
        if(e[i].size()==0)zero++;
        for(j=1;j<(int)e[i].size();j++)
            uu(e[i][j],e[i][j-1]);
    }
    int an=0;
    for(i=0;i<m;i++)
        if(used[i]&&find(i)==i)an++;
    cout<<max(an-1,0)+zero<<endl;
    return 0;
}