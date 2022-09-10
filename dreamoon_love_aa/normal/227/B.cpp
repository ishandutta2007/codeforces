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
#define SIZE 100010
int pos[SIZE];
int main(){
    int i,j,k,n,x,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        pos[x]=i;
    }
    scanf("%d",&m);
    long long an1=0,an2=0;
    while(m--){
        scanf("%d",&x);
        an1+=pos[x];
        an2+=n+1-pos[x];
    }
    cout<<an1<<" "<<an2<<endl;
    return 0;
}