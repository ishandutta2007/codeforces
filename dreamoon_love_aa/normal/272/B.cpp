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
long long cnt[33];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        int tmp=0;
        while(k){
            tmp+=k&1;
            k>>=1;
        }
        cnt[tmp]++;
    }
    long long an=0;
    for(i=0;i<33;i++)an+=cnt[i]*(cnt[i]-1)/2;
    cout<<an<<endl;
    return 0;
}