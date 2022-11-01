#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        long long r,b,d;
        cin>>r>>b>>d;
        d++;
        if(r>b)swap(r,b);
        cout<<(r*d>=b?"YES\n":"NO\n");
    }

    return 0;
}