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
int a[111],b[111];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int an=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(a[i]==b[j])break;
        }
        if(j==n)an++;
    }
    printf("%d\n",an);
    return 0;
}