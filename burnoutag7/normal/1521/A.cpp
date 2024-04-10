#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        if(b==1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n"<<a*b*2-a<<' '<<a<<' '<<a*b*2<<'\n';
        }
    }

    return 0;
}