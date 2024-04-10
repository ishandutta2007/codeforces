#include <bits/stdc++.h>
using namespace std;



int n;
string s;
int c1,c2;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='0') ++c1;
        else ++c2;
    if (c2==0) {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    while (c1>0) {
        --c1;
        cout<<"0";
    }
}