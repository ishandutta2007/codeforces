#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if((n-i)*4+1<=n)cout<<8;
            else cout<<9;
        }
        cout<<'\n';
    }

    return 0;
}