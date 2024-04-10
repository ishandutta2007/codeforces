#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    for(int i=0;i+2<s.size();i++){
        if((s[i]-'A'+s[i+1]-'A')%26!=s[i+2]-'A'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}