#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i)
    if (s[i]=='0'){
        s.erase(s.begin()+i);
        cout<<s;
        return 0;
    }
    s.erase(s.end()-1);
    cout<<s;
}