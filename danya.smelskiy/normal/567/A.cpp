#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    cout<<a[2]-a[1]<<" "<<a[n]-a[1]<<endl;
    for (int i=2;i<n;++i){
        cout<<min(a[i]-a[i-1],a[i+1]-a[i])<<" "<<max(a[i]-a[1],a[n]-a[i])<<endl;
    }
    cout<<a[n]-a[n-1]<<" "<<a[n]-a[1];
}