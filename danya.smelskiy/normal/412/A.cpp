#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s="#"+s;
    int x=m-1;
    int y=n-m;
    int mm=m;
    if (x<=y) {
        while (m>=1) {
            cout<<"PRINT "<<s[m]<<'\n';
            if (m>1) {
                --m;
                cout<<"LEFT"<<'\n';
            } else break;
        }
        while (m<n) {
            cout<<"RIGHT"<<'\n';
            ++m;
            if (m>mm) cout<<"PRINT "<<s[m]<<'\n';
        }
        return 0;
    }
    while (m<=n) {
            cout<<"PRINT "<<s[m]<<'\n';
            if (m<n) {
                ++m;
                cout<<"RIGHT"<<'\n';
            } else break;
    }
        while (m>1) {
            --m;
            cout<<"LEFT"<<'\n';
            if (m<mm)
            cout<<"PRINT "<<s[m]<<'\n';
        }
}