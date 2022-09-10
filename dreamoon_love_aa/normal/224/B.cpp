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
int a[100000];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    map<int,int>H;
    for(i=0;i<n;i++){
        cin>>a[i];
        H[a[i]]++;
        if(H.size()==k)break;
    }
    j=i;
    if(i==n)puts("-1 -1");
    else{
        for(i=0;i<n;i++){
            H[a[i]]--;
            if(H[a[i]]==0)break;
        }
        printf("%d %d\n",i+1,j+1);
    }
    return 0;
}