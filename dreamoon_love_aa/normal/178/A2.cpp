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
#define SIZE 100001
int a[SIZE];
int f(int l,int r){
    int now=0,cnt=0;
    for(int i=14;i>=0;i--){
        if(now+(1<<i)<=r){
            cnt++;
            now+=1<<i;
        }
        if(now>=l)return cnt;
    }
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        long long an=0;
        for(j=1;j<=i;j++){
            an+=a[j]*f(i+1-j,n-j);
        }
        cout<<an<<endl;
    }
    return 0;
}