#include <bits/stdc++.h>
using namespace std;


int n;
int a[200005];
pair<int,int> b[200005];
pair<int,int> c[200005];
string s;
int sz,l;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        b[i]=make_pair(a[i],i);
    }
    sort(b+1,b+n+1);
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='0') {
            c[++sz]=b[++l];
            cout<<b[l].second<<" ";
        } else {
            cout<<c[sz--].second<<" ";
        }
    }
}