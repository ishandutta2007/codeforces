#include <bits/stdc++.h>
using namespace std;

string s,s1;
int main(){
    cin>>s>>s1;
    if (s.size()!=s1.size() || (s.size()==s1.size() && s!=s1)) {
        if (s.size()>s1.size()) cout<<s.size();
        else cout<<s1.size();
        return 0;
    }
    cout<<-1;
}