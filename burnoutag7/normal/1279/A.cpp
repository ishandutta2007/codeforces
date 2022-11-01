#include<bits/stdc++.h>
using namespace std;

int t,a[3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]+1<a[2]){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}