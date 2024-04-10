#include <bits/stdc++.h>
using namespace std;
string s,s1;
string ss,ss2;
long long a,b,kol;
bool t;
int main(){
    cin>>s>>s1;
    for (int i=0;i<s.size();++i){
        if (s[i]=='|') t=true; else
        if (t==false){
            ++a;
            ss+=s[i];
        } else {
            ++b;
            ss2+=s[i];
        }
    }
    if ((a+b+s1.size())%2==0 && (s1.size()>=(max(a,b)-min(a,b)))){
        int x=(a+b+s1.size())/2;
        cout<<ss;
        kol=1;
        for (int i=a+1;i<=x;++i){
            cout<<s1[kol-1];
            ++kol;
        }
        cout<<"|";
        cout<<ss2;
        for (int i=b+1;i<=x;++i){
            cout<<s1[kol-1];
            ++kol;
        }
    } else {
        cout<<"Impossible";
        return 0;
    }
}