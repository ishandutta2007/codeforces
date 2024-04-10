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
bitset<1000000>p;
vector<long long>pp;
int main(){
    int i,j,k,T;
    long long n;
    for(i=2;i<1000;i++)
        if(!p[i])
            for(j=i+i;j<1000000;j+=i)p[j]=1;
    for(i=2;i<1000000;i++)
        if(!p[i])pp.pb((long long)i*i);
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        if(binary_search(pp.begin(),pp.end(),n))puts("YES");
        else puts("NO");
    }
    return 0;
}