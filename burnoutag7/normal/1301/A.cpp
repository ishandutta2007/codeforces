#include<bits/stdc++.h>
using namespace std;

int T;
string a,b,c;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        bool f=true;
        for(int i=0;i<c.size();i++){
            if(!(a[i]==c[i]||b[i]==c[i])){
                f=false;
                break;
            }
        }
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}