#include<bits/stdc++.h>
using namespace std;

int t,a[3],n,nd;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2]>>n;
        sort(a,a+3);
        nd=a[2]-a[0]+a[2]-a[1];
        if(n<nd||(n-nd)%3){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}