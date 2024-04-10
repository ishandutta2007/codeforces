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
int a[100001];
int main(){
    int i,j,k,n,now=0,res=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    k=i=0;
    while(i<n||now){
        if(!now){
            res+=a[i]-k;
            k=a[i];
        }
        while(i<n&&a[i]==k){now++;i++;}
        if(now%2==0)res++;
        now>>=1;
        k++;
    }
    cout<<res<<endl;
    return 0;
}