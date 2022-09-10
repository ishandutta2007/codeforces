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
double dp[SIZE][SIZE];
bool used[SIZE][SIZE];
double f(int player,int w,int b);
double g(int player,int w,int b){
    if(!w)return 0;
    if(!b){
        if(w==1)return 0;
        if(player)return 1;
        return 0;
    }
    if(used[w][b])return dp[w][b];
    used[w][b]=1;
    return dp[w][b]=w*1./(w+b)*f(player,w-1,b)+b*1./(w+b)*f(player,w,b-1);
}
double f(int player,int w,int b){
    if(!w)return 0;
    if(!b){
        if(player)return 1;
        return 0;
    }
    if(used[w][b])return dp[w][b];
    used[w][b]=1;
    if(player){
        return dp[w][b]=w*1./(w+b)+b*1./(w+b)*f(player^1,w,b-1);
    }
    else{
        return dp[w][b]=b*1./(w+b)*g(player^1,w,b-1);
    }
}
int main(){
    int i,j,k,n,w,b;
    cin>>w>>b;
    printf("%.12lf\n",f(1,w,b));
    return 0;
}