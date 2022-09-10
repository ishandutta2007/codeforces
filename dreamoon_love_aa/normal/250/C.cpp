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
int cnt[100010],a[100010];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i=j){
        for(j=i;j<=n&&a[j]==a[i];j++);
        cnt[a[i]]+=1+(a[i-1]==a[j]);
    }
    int an,ma=0;
    for(i=1;i<=k;i++){
        if(ma<cnt[i]){
            ma=cnt[i];
            an=i;
        }
    }
    cout<<an<<endl;
    return 0;
}