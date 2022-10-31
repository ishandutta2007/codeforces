#include <bits/stdc++.h>
using namespace std;



int n,m;
string s;
int sz;
int q[200005];
bool used[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s="#"+s;
    m/=2;
    for (int i=1;i<=n && m>0;++i) {
        if (s[i]=='(') q[++sz]=i;
        else {
            if (sz>0) {
                used[i]=true;
                used[q[sz]]=true;
                --sz;
                --m;
            }
        }
    }
    for (int i=1;i<=n;++i)
        if (used[i]) cout<<s[i];



}