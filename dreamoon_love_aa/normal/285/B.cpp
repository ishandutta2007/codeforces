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
#define SIZE 1000010
int d[SIZE];
int main(){
    int i,j,k,n,s,t;
    cin>>n>>s>>t;
    for(i=1;i<=n;i++)cin>>d[i];
    for(i=0;i<=SIZE;i++){
        if(s==t){
            printf("%d\n",i);
            return 0;
        }
        s=d[s];
    }
    puts("-1");
    return 0;
}