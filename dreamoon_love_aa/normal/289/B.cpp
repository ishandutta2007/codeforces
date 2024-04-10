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
int a[111][111];
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)scanf("%d",&a[i][j]);
    vector<int>d;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if((a[i][j]-a[0][0])%k){
                puts("-1");
                return 0;
            }
            d.pb((a[i][j]-a[0][0])/k);
        }
    sort(d.begin(),d.end());
    int res=0;
    for(i=0;i<(int)d.size()-i;i++)res+=d[d.size()-i-1]-d[i];
    cout<<res<<endl;
    return 0;
}