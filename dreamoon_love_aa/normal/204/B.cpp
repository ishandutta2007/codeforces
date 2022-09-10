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
#define MAX 10000000
int d[200000],a[100000][2],dn,an,n;
void check(int x){
    int i,ha[2]={};
    for(i=0;i<n;i++){
        if(a[i][0]==x)ha[0]++;
        else if(a[i][1]==x)ha[1]++;
    }
    if((ha[0]+ha[1])*2>=n){
        an=min((n+1)/2-ha[0],an);
    }
}
int main(){
    int i,j,k;
    an=MAX;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        d[dn++]=a[i][0];
        d[dn++]=a[i][1];
    }
    sort(d,d+dn);
    for(i=0;i<dn;i=j){
        for(j=i;j<dn&&d[j]==d[i];j++);
        if((j-i)*2>=n)check(d[i]);
    }
    if(an==MAX)puts("-1");
    else printf("%d\n",max(0,an));
    
    return 0;
}