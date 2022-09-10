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
int a[100000],an[1<<20];
vector<int>d[20];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        for(j=0;j<20;j++)
            if((a[i]>>j)&1)d[j].pb(i);
    }
    for(i=0;i<n;i++){
        vector<int>e;
        for(j=0;j<20;j++)
            if(!((a[i]>>j)&1)){
                int idx=lower_bound(d[j].begin(),d[j].end(),i)-d[j].begin();
                if(idx<d[j].size())e.pb(d[j][idx]);
            }
        int now=a[i];
        an[now]=1;
        sort(e.begin(),e.end());
        for(j=0;j<e.size();j++){
            now|=a[e[j]];
            an[now]=1;
        }
    }
    int res=0;
    for(i=0;i<(1<<20);i++)res+=an[i];
    printf("%d\n",res);
    return 0;
}