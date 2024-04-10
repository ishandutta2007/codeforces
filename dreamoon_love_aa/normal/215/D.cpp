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
int main(){
    int i,j,k,n,m,t,T,x,cost;
    long long an=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&t,&T,&x,&cost);
        if(T>t){
            T-=t;
            long long tmp=cost+(long long)(m>T)*m*x;
            if(m>T)tmp=min(tmp,(long long)cost*((m+T-1)/T));
            if(m>2*T){
                long long tmp2=m%T+T;
                tmp=min(tmp,(long long)cost*(1+(m-tmp2)/T)+tmp2*x);
            }
            an+=tmp;
        }
        else{
            an+=cost+(long long)m*x;
        }
    }
    cout<<an<<endl;
    return 0;
}