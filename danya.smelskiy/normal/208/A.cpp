#include <bits/stdc++.h>
using namespace std;
string s;
int i;
bool t;
int main(){
    cin>>s;
    while (i<s.size()){
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
            s.erase(s.begin()+i,s.begin()+i+3);
            s.insert(s.begin()+i,' ');
        } else ++i;
    }
    i=0;
    while (i<s.size()){
        if (i==0 && s[i]==' '){
            s.erase(s.begin());
        } else
        if (s[i]==' ' && s[i+1]==' '){
            s.erase(s.begin()+i,s.begin()+i+1);
        } else ++i;
    }
    cout<<s;
}