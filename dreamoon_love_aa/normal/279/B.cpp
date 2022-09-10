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
int a[100010];
int main(){
    int i,j,k,n,t,an=0;
    cin>>n>>t;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=j=k=0;i<n;i++){
        k=max(k,0);
        j=max(j,i);
        while(j<n&&k+a[j]<=t){
            k+=a[j++];
        }
        k-=a[i];
        an=max(an,j-i);
    }
    cout<<an<<endl;
    return 0;
}