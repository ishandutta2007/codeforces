#include<bits/stdc++.h>
using namespace std;

int n,s,t,q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n>>s>>t;
        int bo=s+t-n;
        int os=n-t;
        int ot=n-s;
        cout<<max(os+1,ot+1)<<endl;
    }

    return 0;
}