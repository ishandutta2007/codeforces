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
#define SIZE 200001
long long a[SIZE];
bool small(long long now,long long n,long long i,long long aa,long long k){
    long long tmp=(n-i)*(i-1);
    if(now<k)return 1;
    now-=k;
    if(now/aa>=tmp)return 0;
    return 1;
}
int main(){
    int i,j,n,nn;
    long long k,now=0;
    cin>>n>>k;
    nn=n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++){
        if(i!=1&&small(now,nn,i-(n-nn),a[i],k)){
            nn--;
            cout<<i<<endl;
        }
        else{
            now+=a[i]*(i-(n-nn)-1);
        }
    }
    return 0;
}