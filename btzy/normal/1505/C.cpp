#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    string str;
    cin>>str;
    if(str.size()<=2) {
        cout<<"YES\n";
        return 0;
    }
    for (size_t i=2;i!=str.size();++i){
        if(((str[i-2]-'A')+(str[i-1]-'A'))%26!=(str[i]-'A')){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}