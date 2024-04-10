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
#define SIZE 1000100
#define MOD 1000000007
int d[SIZE],two[SIZE];
int main(){
    int i,j,k,n,mi=100000000,ma=0,cnt=0,m;
    long long res=0;
    two[0]=1;
    for(i=1;i<SIZE;i++){
        two[i]=two[i-1]<<1;
        if(two[i]>=MOD)two[i]-=MOD;
    }
    scanf("%d%d%d",&n,&m,&k);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x+1!=y){
            if(x+k+1==y){
                cnt++;
                d[x]=1;
                mi=min(mi,x);
                ma=max(ma,x);
            }
            else{
                puts("0");
                return 0;
            }
        }
    }
    if(!ma){
        res=1;
        for(i=1;i<=n-k-1;i++){
            res+=two[min(i,k+1)-1];
            if(res>=MOD)res-=MOD;
        }
        cout<<res<<endl;
    }
    else{
        if(mi+k+1<=ma){
            puts("0");
            return 0;
        }
        res=two[min(ma,k+1)-cnt];
        for(i=ma+1;i<mi+k+1&&i<=n-k-1;i++){
            res+=two[min(i,k+1)-cnt-1];
            if(res>=MOD)res-=MOD;
        }
        cout<<res<<endl;

    }
    return 0;
}