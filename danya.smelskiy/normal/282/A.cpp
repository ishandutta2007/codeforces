#include <bits/stdc++.h>
using namespace std;
int n,x;
string s;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (s[0]=='+' || s[1]=='+' || s[2]=='+') ++x;
        else --x;
    }
    cout<<x;
}