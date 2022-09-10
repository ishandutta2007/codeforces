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
int a[10001];
int main(){
    int i,j,k,kk,n,an=0;
    cin>>n;
    for(i=3;i<=10000;i++)a[i]=i*i;
    for(j=3;j<n;j++){
        for(k=j+1,kk=j+2;k<n&&kk<=n;k++){
            while(kk<=n&&a[j]+a[k]>a[kk])kk++;
            if(a[j]+a[k]==a[kk])an++;
        }
    }
    cout<<an<<endl;
    return 0;
}