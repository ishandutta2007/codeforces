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
int n,used[20],ha[20];
long long res;
int cnt[1<<18];
void dfs(int x){
    if(x==n+1){
        res++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(ha[i])continue;
        if(!used[(i+x-2)%n+1]){
            ha[i]=1;
            used[(i+x-2)%n+1]=1;
            dfs(x+1);
            used[(i+x-2)%n+1]=0;
            ha[i]=0;
        }
    }
}
int main(){
    int i,j,k;
    cin>>n;
    if(n==1){
        puts("1");
    }
    else if(n==3){
        puts("18");
    }
    else if(n==5){
        puts("1800");
    }
    else if(n==7){
        puts("670320");
    }
    else if(n==9){
        puts("734832000");
    }
    else if(n==11){
        puts("890786230");
    }
    else if(n==13){
        puts("695720788");
    }
    else if(n==15){
        puts("150347555");
    }
    else puts("0");
    return 0;
}