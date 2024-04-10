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
int d[31]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int cnt[31];
set<int>H;
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=2;i*i<=n;i++){
        if(H.count(i))continue;
        long long now=i*i;
        H.insert(i);
        H.insert(now);
        int cc=2;
        while(now*i<=n){
            cc++;
            now*=i;
            H.insert(now);
        }
        cnt[cc]++;
    }
    int res=0;
    cnt[1]+=n-H.size();
    for(i=1;i<=30;i++)
        if(cnt[i]&1)res^=d[i];
    if(res)puts("Vasya");
    else puts("Petya");
    return 0;
}