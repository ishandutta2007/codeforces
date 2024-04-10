#include <bits/stdc++.h>
using namespace std;

string s;
int ans,sz;
int kol;
pair<char,int> q[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    kol=1;
    for (int i=1;i<=s.size();++i) {
        if (s[i-1]=='(') {
            ++sz;
            q[sz]=make_pair('(',i);
        } else {
            if (sz && q[sz].first=='(') {
                    --sz;
            } else {
                ++sz;
                q[sz]=make_pair(')',i);
            }
        }
        if (i-q[sz].second>ans) {
            ans=i-q[sz].second;
            kol=1;
        } else if (i-q[sz].second==ans) ++kol;
    }
    if (ans==0) kol=1;
    cout<<ans<<" "<<kol;
}