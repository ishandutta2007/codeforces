#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
bool t;
string s;
int main(){
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='<' && t==false) {++ans; k=0;}
        else if (s[i]=='>'){
            t=true;
            ++k;
        } else if (s[i]=='<') k=0;
    }
    cout<<ans+k;
}