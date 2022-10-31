#include <bits/stdc++.h>
using namespace std;

string s;
int kol[100];

int main(){
    cin>>s;
    for (int i=0;i<s.size();++i)
        ++kol[s[i]-'a'];
    int it=0;
    for (int i=1;i<=s.size();++i) {
        int t1=0,t2=0;
        ++it;
        for (int j=0;j<26;++j)
            if (kol[j]&1) ++t1;
            else if (kol[j]) ++t2;
        if (t1<=1) {
            if (it&1) cout<<"First";
            else cout<<"Second";
            return 0;
        }
            if (t2) {
            for (int j=0;j<26;++j)
                if (kol[j]%2==0 && kol[j]) {
                    --kol[j];
                    break;
                }
            } else {
                for (int j=0;j<26;++j)
                if (kol[j]&1) {
                    --kol[j];
                    break;
                }
            }
    }
}