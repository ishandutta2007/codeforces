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
int a[111],b[111][111],an[111];
void error(){
    //do nothing;
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)cin>>b[i][j];
    for(i=1;i<=n;i++){
        if(b[i][i]!=-1)error();
        for(j=i+1;j<=n;j++){
            if(b[i][j]!=b[j][i])error();
        }
        for(j=1;j<=n;j++)
            if(j!=i){
                an[j]|=b[i][j];
            }
    }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if((an[i]&an[j])!=b[i][j])error();
    for(i=1;i<=n;i++)printf("%d%c",an[i],i<n?' ':'\n');
    return 0;
}