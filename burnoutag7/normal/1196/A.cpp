#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll a,b,c;

ll dvd(ll x,ll y,ll z){
    return min(x+z,min(y+z,(x+y+z)/2));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>a>>b>>c;
        cout<<max(dvd(a,b,c),max(dvd(b,c,a),dvd(a,c,b)))<<endl;
    }

    return 0;
}