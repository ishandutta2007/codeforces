#include<bits/stdc++.h>
using namespace std;

int T,a[3],n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>a[0]>>a[1]>>n;
        a[2]=a[0]^a[1];
        cout<<a[n%3]<<endl;
    }

    return 0;
}