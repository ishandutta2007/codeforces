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
#define SIZE 15000
long long a[SIZE];
bool eq(long long p,long long q,int n,long long d[]){
    if(n==1){
        return q*d[0]==p&&p/q==d[0];
    }
    if(p/q<d[0])return 0;
    p-=q*d[0];
    if(p==0)return 0;
    swap(p,q);
    return eq(p,q,n-1,d+1);
}
int main(){
    int i,j,k,n;
    long long p,q;
    cin>>p>>q>>n;
    for(i=0;i<n;i++)cin>>a[i];
    if(eq(p,q,n,a))puts("YES");
    else puts("NO");
    return 0;
}