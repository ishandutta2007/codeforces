#include <bits/stdc++.h>
using namespace std;
string s,s1;
int i;
int main(){
    cin>>s>>s1;
    for (i=0;i<s.size();++i)
        if (s[i]!='0') break;
    if (i!=0){
        s.erase(s.begin(),s.begin()+i);
    }
    for (i=0;i<s1.size();++i)
        if (s1[i]!='0') break;
    if (i!=0)
        s1.erase(s1.begin(),s1.begin()+i);
    if (s.size()>s1.size()) cout<<">";
    else if (s.size()<s1.size()) cout<<"<";
    else {
        for (int i=1;i<=s.size();++i){
            if (s[i-1]>s1[i-1]) { cout<<">"; return 0;}
            else if (s[i-1]<s1[i-1]) { cout<<"<"; return 0;}
        }
        cout<<"=";
    }
}