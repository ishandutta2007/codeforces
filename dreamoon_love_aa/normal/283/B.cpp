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
#define SIZE 200001
int a[SIZE],n;
long long v[SIZE][2];
vector<pair<int,int> >e[SIZE][2];
int main(){
    int i,j,k;
    v[1][0]=-1;
    scanf("%d",&n);
    for(i=2;i<=n;i++)scanf("%d",&a[i]);
    vector<pair<int,int> >qq;
    for(i=2;i<=n;i++){
        if(i+a[i]>n){
            qq.pb(make_pair(i,1));
            v[i][1]=a[i];
        }
        else{
            e[i+a[i]][0].pb(make_pair(i,1));
        }
        if(i-a[i]<=0){
            qq.pb(make_pair(i,0));
            v[i][0]=a[i];
        }
        else{
            e[i-a[i]][1].pb(make_pair(i,0));
        }
    }
    for(i=0;i<qq.size();i++){
        for(j=0;j<e[qq[i].first][qq[i].second].size();j++){
            pair<int,int>now=e[qq[i].first][qq[i].second][j];
            qq.pb(now);
            v[now.first][now.second]=v[qq[i].first][qq[i].second]+a[now.first];
        }
    }
    for(i=1;i<n;i++){
        if(!v[i+1][0])puts("-1");
        else cout<<v[i+1][0]+i<<endl;
    }
    return 0;
}