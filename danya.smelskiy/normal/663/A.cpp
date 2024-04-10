#include <bits/stdc++.h>
using namespace std;


string s;
vector<char> v;
int pos,neg;
int res;
int n;


int main() {
    getline(cin,s);
    for (int i=0;i<s.size();++i) {
        if (s[i]=='+' || s[i]=='-') v.push_back(s[i]);
        else if (s[i]=='?') {
            if (i==0 || s[i-2]=='+') ++pos;
            else ++neg;
        } else if (s[i]!='=' && s[i]!=' ') n=(n*10+(s[i]-'0'));
    }
    if (!(pos-neg*n<=n && pos*n-neg>=n)) {
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible"<<'\n';
    for (int i=1;i<=n;++i) {
        int l=i+(pos-1)-neg*n;
        int r=i+(pos-1)*n-neg;
        if (l<=n && n<=r) {
            cout<<i;
            --pos;
            res=i;
            break;
        }
    }
    for (int i=0;i<v.size();++i) {
        cout<<" "<<v[i]<<" ";
        if (v[i]=='-') --neg;
        else --pos;
        for (int j=1;j<=n;++j) {
            int l=res+pos-neg*n;
            int r=res+pos*n-neg;
            if (v[i]=='-') l-=j,r-=j;
            else l+=j,r+=j;
            if (l<=n && n<=r) {
                cout<<j;
                if (v[i]=='-') res-=j;
                else res+=j;
                break;
            }
        }
    }
    cout<<" = ";
    cout<<n;
}