#include <bits/stdc++.h>
using namespace std;


int n;
string s[100005];
vector<pair<pair<long ,long long >,int> > v;


inline bool cmp(pair<pair<long long ,long long >,int> x,pair<pair<long long ,long long >,int> y) {
    return (x.first.first*y.first.second>y.first.first*x.first.second);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        int c1=0,c2=0;
        for (int j=0;j<s[i].size();++j)
            if (s[i][j]=='s') ++c1;
        else if (s[i][j]=='h') ++c2;
        v.push_back(make_pair(make_pair(c1,c2),i));
    }
    sort(v.begin(),v.end(),cmp);
    string res="";
    for (int i=0;i<v.size();++i)
        res+=s[v[i].second];
    long long kol=0;
    long long ans=0;
    for (int i=0;i<res.size();++i)
        if (res[i]=='s') ++kol;
        else if (res[i]=='h') ans+=kol;
    cout<<ans;
}