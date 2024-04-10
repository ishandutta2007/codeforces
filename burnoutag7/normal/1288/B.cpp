#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,a,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a>>b;
        ll cur=9,cnt=0;
        while(cur<=b){
            cur=cur*10+9;
            cnt++;
        }
        cout<<cnt*a<<endl;
    }

    return 0;
}