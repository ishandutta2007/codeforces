#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n,g,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>g>>b;
        ll hf=(n+1)/2;
        ll seg=hf/g;
        ll lft=hf%g;
        ll res=0;
        if(lft){
            res=seg*(g+b)+lft;
        }else{
            res=seg*(g+b)-b;
        }
        cout<<max(n,res)<<endl;
    }

    return 0;
}