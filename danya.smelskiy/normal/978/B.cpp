#include <bits/stdc++.h>
using namespace std;




int n;
int ans;
string s;
int last;

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='x') ++last;
        else last=0;
        if (last>=3) ++ans;
    }
    cout<<ans;
}