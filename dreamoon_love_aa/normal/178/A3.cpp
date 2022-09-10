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
long long an[SIZE];
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
        int now=i;
        an[now+1]+=a[i];
        for(j=20;j>=0;j--){
            if(now+(1<<j)<=n){
                now+=1<<j;
                an[now+1]+=a[i];
            }
        }
    }
    for(i=1;i<=n;i++)an[i]+=an[i-1];
    for(i=2;i<=n;i++)cout<<an[i]<<endl;
    return 0;
}