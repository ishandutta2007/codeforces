#include<bits/stdc++.h>
using namespace std;

int n;
int a[300005];
int k;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    k=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k=min(k,a[i]/max(i-1,n-i));
    }
    cout<<k<<endl;

    return 0;
}