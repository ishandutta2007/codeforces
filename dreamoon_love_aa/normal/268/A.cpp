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
int d[2][111];
int main(){
    int i,j,k,n,x,y;
    int res=0;
    cin>>n;
    while(n--){
        cin>>x>>y;
        if(x==y)res--;
        d[0][x]++;
        d[1][y]++;
    }
    for(i=1;i<=100;i++)res+=d[0][i]*d[1][i];
    cout<<res<<endl;
    return 0;
}