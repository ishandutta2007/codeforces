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
int r[10000];
const double pi=acos(-1);
int main(){
    int i,j,k,n;
    double an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>r[i];
    sort(r,r+n);
    int tmp=1;
    for(i=1;i<=n;i++){
        an+=tmp*r[n-i]*r[n-i]*pi;
        tmp=-tmp;
    }
    cout<<an<<endl;
    return 0;
}