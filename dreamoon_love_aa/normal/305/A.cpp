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
bool zero(int x){
    if(!x)return 1;
    while(x){
        if(x%10==0)return 1;
        x/=10;
    }
    return 0;
}
int main(){
    int i,j,k,n;
    vector<int>d[3],res;
    cin>>k;
    for(i=0;i<k;i++){
        cin>>j;
        if(!j||j==100)res.pb(j);
        else{
            if(j<10)d[0].pb(j);
            else if(j%10==0)d[1].pb(j);
            else d[2].pb(j);
        }
    }
    if(d[0].size())res.pb(d[0][0]);
    if(d[1].size())res.pb(d[1][0]);
    if(!d[0].size()&&!d[1].size()&&d[2].size())res.pb(d[2][0]);
    printf("%d\n",(int)res.size());
    for(i=0;i<res.size();i++){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    return 0;
}