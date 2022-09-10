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
int x[100000];
long long f(long long xx){
    return xx*(xx-1)/2;
}
int main(){
    int i,j,k,n,d;
    long long an=0;
    cin>>n>>d;
    for(i=0;i<n;i++)cin>>x[i];
    for(i=0,j=0;i<n;i++){
        while(j<n-1&&x[j+1]-x[i]<=d)j++;
        an+=f(j-i);
    }
    cout<<an<<endl;
    return 0;
}