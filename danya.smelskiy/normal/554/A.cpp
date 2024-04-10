#include <bits/stdc++.h>
using namespace std;

string s;
int kol,kol2;
bool t;
int main(){
    cin>>s;
    for (int i=1;i<s.size();++i){
        if (s[i]==s[i-1]) { ++kol; if (t==false) ++kol2; t=true;}
        else t=false;
    }
    cout<<(s.size()+1)*26-s.size();//-kol-kol2*2;
}