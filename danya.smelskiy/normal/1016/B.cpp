#include <bits/stdc++.h>
using namespace std;




int n,m,q;
string a,b;
int p[200005];
int ans[200005];
string s;


void solve(string s,int x) {
    for (int i=1;i<s.size();++i) {
        int j=p[i-1];
        while (j && s[j]!=s[i]) j=p[j-1];
        if (s[j]==s[i]) ++j;
        p[i]=j;
        if (i>x && p[i]==x) ans[i-x]=1;
    }
}

int main() {
//    freopen("army.in","r",stdin);
  //  freopen("army.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    cin>>a>>b;
    s=b+"#"+a;
    solve(s,m);
    for (int i=1;i<=n;++i)
        ans[i]+=ans[i-1];
    while (q--) {
        int x,y;
        cin>>x>>y;
        if (y-x+1<m) cout<<"0"<<'\n';
        else cout<<ans[y]-ans[x+m-2]<<'\n';
    }
}