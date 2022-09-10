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
int a[5],p[55];
long long an[5];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&p[i]);
    for(i=0;i<5;i++)scanf("%d",&a[i]);
    int now=0;
    for(i=0;i<n;i++){
        now+=p[i];
        for(j=4;j>=0;j--)
            if(now>=a[j]){an[j]+=now/a[j];now%=a[j];}
    }
    for(i=0;i<5;i++){
        if(i)printf(" ");
        cout<<an[i];
    }
    puts("");
    cout<<now<<endl;
    return 0;
}