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
int a[100010],last[100010],now[100010];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=m;i++){
        now[i]=now[i-1];
        int qq;
        cin>>qq;
        if(qq==1){
            cin>>j>>k;
            last[j]=i;
            a[j]=k;
        }
        else if(qq==2){
            cin>>j;
            now[i]+=j;
        }
        else{
            cin>>j;
            printf("%d\n",a[j]+now[i]-now[last[j]]);
        }
    }
    return 0;
}