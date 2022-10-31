#include <bits/stdc++.h>
using namespace std;


int n;
int a[100];
int b[100];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int x=1;
        if (s=="M") {}
        else {
            x+=(s.size()-1)*2;
            if (s[(int)s.size()-1]=='L') ++x;
            else x+=2;
        }
        ++a[x];
    }
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int x=1;
        if (s=="M") {}
        else {
            x+=(s.size()-1)*2;
            if (s[(int)s.size()-1]=='L') ++x;
            else x+=2;
        }
        ++b[x];
    }
    int ans=0;
    for (int i=1;i<=9;++i) {
        a[i]=max(a[i],b[i])-min(a[i],b[i]);
        ans+=a[i];
    }
    ans/=2;
    cout<<ans;
}