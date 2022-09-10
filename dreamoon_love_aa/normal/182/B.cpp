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
int a[1000000],d;
int main(){
    int i,j,k,n,an=0;
    cin>>d>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=2;i<=n;i++){
        if(a[i-1]!=d)an+=d-a[i-1];
    }
    cout<<an<<endl;
    return 0;
}