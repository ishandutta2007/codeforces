#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    if(a<b){
        ll res=1;
        for(ll i=1;i<=a;i++)res*=i;
        cout<<res<<endl;
    }else{
        ll res=1;
        for(ll i=1;i<=b;i++)res*=i;
        cout<<res<<endl;
    }

    return 0;
}