#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n>30)
            if(n!=36&&n!=40&&n!=44)
                cout<<"YES\n6 10 14 "<<n-30<<'\n';
            else
                cout<<"YES\n6 10 15 "<<n-31<<'\n';
        else
            cout<<"NO\n";
    }

    return 0;
}