#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
long long d[11],e[11];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        if(k<0)d[-k]++;
        else e[k]++;
    }
    long long an=0;
    for(i=1;i<=10;i++)an+=d[i]*e[i];
    an+=e[0]*(e[0]-1)/2;
    cout<<an<<endl;
    return 0;
}