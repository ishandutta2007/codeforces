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
int k;
long long f(long long x){
    long long an=0,now=1;
    while(x>=now){
        an+=x/now;
        now*=k;
    }
    return an;
}
int main(){
    int i,j,n;
    long long ll=1,rr;
    cin>>n>>k;
    rr=n;
    while(ll<rr){
        long long mm=(ll+rr)/2;
        if(f(mm)<n)ll=mm+1;
        else rr=mm;
    }
    cout<<ll<<endl;
    return 0;
}