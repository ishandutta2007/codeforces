#include <bits/stdc++.h>
using namespace std;

string s,ss,ans;
int kol[10];

int main(){
    cin>>s>>ss;
    for (int i=1;i<=s.size();++i) {
        ++kol[s[i-1]-'0'];
    }
    for (int i=1;i<=9;++i)
    if (kol[i]) {
        --kol[i];
        ans+=char('0'+i);
        break;
    }
    for (int i=0;i<=9;++i)
        while (kol[i]) {
            ans+=char(i+'0');
            --kol[i];
        }
    if (ans==ss) cout<<"OK";
    else cout<<"WRONG_ANSWER";
}