#include <bits/stdc++.h>
using namespace std;


int kol[10],ans;

int main(){
    for (int i=1;i<=8;++i)  {
        string s;
        cin>>s;
        s="#"+s;
        bool t=false;
        for (int j=1;j<=8;++j) if (s[j]=='B') {
            ++kol[j];
        } else t=true;
        if (!t) ++ans;
    }
    for (int i=1;i<=8;++i)
        if (kol[i]==8) ++ans;
    cout<<(ans==16 ? 8 : ans);
}