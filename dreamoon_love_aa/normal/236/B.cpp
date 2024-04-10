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
int cnt[1000001];
int main(){
    int i,j,k,n,a,b,c;
    for(i=1;i<=1000000;i++)
        for(j=i;j<=1000000;j+=i)cnt[j]++;
    cin>>a>>b>>c;
    int an=0;
    for(i=1;i<=a;i++)
        for(j=1;j<=b;j++)
            for(k=1;k<=c;k++)an+=cnt[i*j*k];
    an%=1<<30;
    if(an<0)an+=1<<30;
    cout<<an<<endl;
    return 0;
}