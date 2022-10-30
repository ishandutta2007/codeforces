#include <bits/stdc++.h>
using namespace std;
string s;
bool t,t1;
int main(){
    cin>>s;
    if (s[0]>='A' && s[0]<='Z') t=true;
    for (int i=1;i<s.size();++i){
        if (s[i]>='a' && s[i]<='z') t1=true;
    }
    if (t==true && t1==false){
        for (int i=0;i<s.size();++i)
            s[i]+=32;
    } else if (t==false && t1==false){
        s[0]-=32;
        for (int i=1;i<s.size();++i)
            s[i]+=32;
    }
    cout<<s;
}