#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
#define pb push_back
#define MAX 10000000000000000ll
using namespace std;
long long fac[16];
vector<long long>lucky;
set<long long>hash;
void dfs(long long v){
    if(v>=MAX)return;
    if(v)lucky.pb(v),hash.insert(v);
    dfs(v*10+4);
    dfs(v*10+7);
}
int lower(long long n){
    int i;
    for(i=0;i<lucky.size()&&lucky[i]<=n;i++);
    return i;
}
bool used[20];
int Go(int start,int n,int k){
    int i,j,an=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(used[j])continue;
            if(k<=fac[n-i]){
                used[j]=1;
                if(hash.count(start+i)&&hash.count(start+j))an++;
                break;
            }
            else{
                k-=fac[n-i];
            }
        }
    }
    return an;
}
int main(){
    int i,j,k,an=0,n;
    fac[0]=1;
    for(i=1;i<=15;i++)fac[i]=fac[i-1]*i;
    dfs(0);
    sort(lucky.begin(),lucky.end());
    scanf("%d%d",&n,&k);
    if(n<=15){
        if(fac[n]<k)an=-1;
        else an=Go(0,n,k);
    }
    else{
        an=lower(n-15)+Go(n-15,15,k);
    }
    cout<<an<<endl;
    return 0;
}