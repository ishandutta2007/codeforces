#include <bits/stdc++.h>
using namespace std;
int n;
long long maxim;
int a[100001];
int b[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    maxim=a[n];
    for (int i=n-1;i>0;--i){
        if (a[i]<=maxim){
            b[i]=maxim+1-a[i];
        } else maxim=a[i];
    }
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
}