#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
msi a,b;vc<pair<string,int> > v;set<string> s;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;int t;
        cin>>x>>t;
        v.pb({x,t});
        a[x]+=t;
    }
    int m=0;
    for(msi::iterator i=a.begin();i!=a.end();i++)if(m<(i->sc))m=i->sc;
    for(msi::iterator i=a.begin();i!=a.end();i++)if(m==(i->sc))s.insert(i->fr);
    for(int i=0;i<n;i++){
        if(s.find(v[i].fr)==s.end())continue;
        b[v[i].fr]+=v[i].sc;
        if(b[v[i].fr]>=m){
            cout<<v[i].fr;return 0;
        }
    }
}