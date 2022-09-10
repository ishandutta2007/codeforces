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
int an[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    k=n;
    while(k>0){
        for(i=1;i<k;i=i*2+1);
        for(j=k;j>=i-k;j--)an[j]=i-j;
        k=i-k-1;
    }
    cout<<(long long)n*(n+1)<<endl;
    for(i=0;i<=n;i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    return 0;
}