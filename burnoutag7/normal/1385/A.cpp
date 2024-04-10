#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y,z;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>x>>y>>z;
        a=min(x,y);
        b=min(x,z);
        c=min(y,z);
        if(max(a,b)!=x||max(a,c)!=y||max(b,c)!=z){
            cout<<"NO\n";
        }else{
            cout<<"YES\n"<<a<<' '<<b<<' '<<c<<'\n';
        }
    }

    return 0;
}