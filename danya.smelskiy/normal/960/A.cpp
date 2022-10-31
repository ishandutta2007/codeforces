#include <bits/stdc++.h>
using namespace std;






string s;
int c1,c2,c3;
bool t1,t2,t3;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='a') t1=true;
        else if (s[i]=='b') t2=true;
        else if (s[i]=='c') t3=true;
        else {
            cout<<"NO";
            return 0;
        }
        if (s[i]=='a' && (t2||t3)) {
            cout<<"NO";
            return 0;
        }
        if (s[i]=='b' && (t3)) {
            cout<<"NO";
            return 0;
        }
        if (s[i]=='a') ++c1;
        else if (s[i]=='b') ++c2;
        else ++c3;
    }
    if (!c1 || !c2 || !c3) {
        cout<<"NO";
        return 0;
    }
    if (c3==c1 || c3==c2) cout<<"YES";
    else cout<<"NO";
}