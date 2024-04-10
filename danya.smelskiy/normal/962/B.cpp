#include <bits/stdc++.h>
using namespace std;



string s;
int n,a,b;
int c1,c2;
int last;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    cin>>s;
    s="#"+s;
    for (int i=1;i<=n;++i) {
        if (s[i]=='.') {
            ++last;
            if (i==n || s[i+1]=='*') {
                c1+=last/2;
                c2+=last%2;
                last=0;
            }
        } else last=0;
    }
    int z=min(a,b);
    z=min(z,c1);
    c1-=z;
    c2+=c1;
    int ans=0;
    ans+=z+z;
    a-=z;
    b-=z;
    ans+=min(a+b,c2);
    cout<<ans;

}