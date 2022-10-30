#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;

int main(){
    cin>>n;
    cin>>s;
    if (s[0]=='0'){
        cout<<"1";
        return 0;
    } else{
        for (int i=0;i<s.size();++i)
            if (s[i]=='1') ++ans;
        else break;
        ++ans;
        if (s[s.size()-1]=='1' && ans>s.size())--ans;
    }
        cout<<ans;
}