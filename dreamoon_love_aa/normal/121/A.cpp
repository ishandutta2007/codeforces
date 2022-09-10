#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define MAX 10000000000ll
vector<long long>lucky;
void dfs(long long v){
    if(v>=MAX)return;
    if(v)lucky.pb(v);
    dfs(v*10+4);
    dfs(v*10+7);
}
long long f(long long x1,long long y1,long long x2,long long y2){
    if(max(x1,x2)>min(y1,y2))return 0;
    return min(y1,y2)-max(x1,x2)+1;
}
int main(){
    long long i,j,k=0;
    long long an=0;
    dfs(0);
    sort(lucky.begin(),lucky.end());
    cin>>j>>k;
    for(i=0;i<lucky.size();i++){
        if(i==0){
            an+=f(j,k,1,4)*4;
        }
        else{
            if(lucky[i-1]>=k)break;
            an+=f(j,k,lucky[i-1]+1,lucky[i])*lucky[i];
        }
    }
    cout<<an<<endl;
    return 0;
}