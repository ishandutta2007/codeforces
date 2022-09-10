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
int main(){
    int i,j,k,n,w,h;
    long long res=0;
    cin>>w>>h;
    for(i=1;i*2<=w;i++)
        for(j=1;j*2<=h;j++)
            res+=(h-2*j+1)*(w-2*i+1);
    cout<<res<<endl;
    return 0;
}