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
int a[1111];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++){
        k=0;
        for(j=i;j<n;j++){
            k^=a[j];
            an=max(an,k);
        }
    }
    cout<<an<<endl;
    return 0;
}