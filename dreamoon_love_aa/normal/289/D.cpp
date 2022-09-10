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
#define MOD 1000000007
using namespace std;
long long cnt;
int d[10];
void dfs(int x,int n){
    if(x>n){
        int i,j,k;
        for(i=2;i<=n;i++){
            j=i;
            for(k=0;k<n;k++){
                j=d[j];
                if(j==1)break;
            }
            if(k==n)return;
        }
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        d[x]=i;
        dfs(x+1,n);
    }
}
int main(){
    int i,j,k,n;
    d[1]=1;
    cin>>n>>k;
    dfs(2,k);
    cnt*=k;
    for(i=k+1;i<=n;i++){
        cnt*=(n-k);
        cnt%=MOD;
    }
    cout<<cnt<<endl;
    return 0;
}