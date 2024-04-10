#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<n;i++){
        a[i]=i+1;
    }
    a[n]=1;
    if(n==k){cout<< -1;return 0;}
    while(k-->0){
        int t=a[1];
        a[1]=a[t];
        a[t]=t;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}