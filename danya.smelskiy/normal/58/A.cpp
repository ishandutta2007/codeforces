#include <bits/stdc++.h>
using namespace std;
bool t1,t2,t3,t4,t5;
string s;
//ahelo
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='h') t1=true;
        if (s[i]=='e' && t1==true) t2=true;
        if (s[i]=='l' && t3==true) t4=true;
        if (s[i]=='l' && t2==true)  t3=true;
        if (s[i]=='o' && t4==true) t5=true;
    }
    if (t5==true) cout<<"YES";
    else cout<<"NO";
}