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
#define SIZE 100001
vector<int>fac[SIZE];
bitset<SIZE>p;
vector<int>pp;
int dp[SIZE],an;
int get(int x){
    return lower_bound(pp.begin(),pp.end(),x)-pp.begin();
}
int main(){
    int i,j,k,n;
    for(i=2;i<SIZE;i++){
        if(!p[i]){
            pp.pb(i);
            for(j=i;j<SIZE;j+=i){p[j]=1;fac[j].pb(i);}
        }
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int ma=0;
        for(j=0;j<fac[x].size();j++){
            ma=max(ma,dp[get(fac[x][j])]);
        }
        for(j=0;j<fac[x].size();j++){
            int tmp=get(fac[x][j]);
            dp[tmp]=max(dp[tmp],ma+1);
        }
        an=max(an,ma+1);
    }
    printf("%d\n",an);
    return 0;
}