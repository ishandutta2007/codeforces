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
#define SIZE 1111
int ff[SIZE],pp[SIZE],dp[SIZE];
vector<int>d;
int main(){
    int i,j,k,n,x,pos;
    cin>>n>>x;
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        pp[i]=k;
        if(k)ff[k]=i;
    }
    for(i=1;i<=n;i++){
        if(!pp[i]){
            bool flag=1;
            k=0;
            j=i;
            while(ff[j]){
                if(j==x){
                    pos=k;
                    flag=0;
                }
                j=ff[j];
                k++;
            }
            if(j==x){
                pos=k;
                flag=0;
            }
            if(flag)d.pb(k+1);
        }
    }
    dp[0]=1;
    for(i=0;i<d.size();i++){
        for(j=n-d[i];j>=0;j--)
            if(dp[j])dp[j+d[i]]=1;
    }
    for(i=0;i<n;i++){
        if(dp[i])printf("%d\n",i+1+pos);
    }
    return 0;
}