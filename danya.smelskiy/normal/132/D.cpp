#include <bits/stdc++.h>
using namespace std;

string s;
vector<pair<int,int> > ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    s+="0";
    for (int i=0;i<=n;++i) {
        if (s[i]=='0') continue;
        if (i==n || s[i+1]=='0') ans.push_back(make_pair(0,i));
        else {
            ans.push_back(make_pair(1,i));
            while (i<=n && s[i]=='1') {
                s[i]='0';
                ++i;
            }
            s[i]='1';
            --i;
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<(ans[i].first==0 ? '+' : '-')<<"2^"<<ans[i].second<<'\n';
}