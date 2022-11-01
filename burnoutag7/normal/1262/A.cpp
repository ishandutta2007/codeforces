#include<bits/stdc++.h>
using namespace std;

int t,n,l,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        r=0;l=1e9;
        while(n--){
            int a,b;
            cin>>a>>b;
            l=min(l,b);
            r=max(r,a);
        }
        cout<<max(r-l,0)<<endl;
    }

    return 0;
}