#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[300005];
int d[300005];
long long sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i-1]=a[i]-a[i-1];
        sum+=d[i-1];
    }
    sum-=d[0];
    //cout<<sum<<endl;
    sort(d+1,d+1+n);
    for(int i=n;i>=n-k+2;i--){
        sum-=d[i];
    }
    cout<<sum<<endl;

    return 0;
}