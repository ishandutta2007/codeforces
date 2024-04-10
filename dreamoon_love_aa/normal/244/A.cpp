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
vector<int>d[33];
int used[333333];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    for(i=0;i<k;i++){
        cin>>j;
        d[i].pb(j);
        used[j]=1;
    }
    j=1;
    for(i=0;i<k;i++){
        while(d[i].size()<n){
            if(used[j]==0){
                d[i].pb(j++);
            }
            else j++;
        }
    }
    for(i=0;i<k;i++,puts("")){
        for(j=0;j<n;j++){
            if(j)printf(" ");
            printf("%d",d[i][j]);
        }
    }
    return 0;
}