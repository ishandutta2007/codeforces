#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[n-1]+a[n-2]<=a[n]){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    swap(a[n-1],a[n]);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    return 0;
}