#include<bits/stdc++.h>
using namespace std;

string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int d;
    for(int i=0;i<s.size();i++){
        d*=16;d+=s[i]-'0';
    }
    cout<<(d&1)<<endl;

    return 0;
}