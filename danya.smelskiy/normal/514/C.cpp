#include <bits/stdc++.h>
using namespace std;
const long long md=1e11+7;
int n,m;
map<long long,bool> used;
long long p[600005];
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    p[0]=1;
    for (int i=1;i<=6*1e5;++i)
        p[i]=(p[i-1]*31)%md;
    for (int i=1;i<=n;++i) {
        cin>>s;
        long long hsh=0;
        for (int j=1;j<=s.size();++j) {
            hsh=(hsh+(s[j-1]-'a'+1)*p[j])%md;
        }
        used[hsh]=true;
    }
    for (int i=1;i<=m;++i) {
        cin>>s;
        long long hsh=0;
        bool t=false;
        for (int j=1;j<=s.size();++j)
            hsh=(hsh+(s[j-1]-'a'+1)*p[j])%md;
        long long hh=0;
        for (int i=1;i<=s.size();++i) {
            hsh-=((s[i-1]-'a'+1)*p[i])%md;
            if (hsh<0) hsh+=md;
            for (int j=0;j<3;++j)
            if (s[i-1]!=('a'+j)) {
                long long hh1=(hh+(j+1)*p[i])%md;
                hh1=(hh1+hsh)%md;
                if (used[hh1]) {
                    t=true;
                    break;
                }
            }
            if (t) break;
            hh=(hh+(s[i-1]-'a'+1)*p[i])%md;
        }
        if (t) cout<<"YES\n";
        else cout<<"NO\n";
    }
}