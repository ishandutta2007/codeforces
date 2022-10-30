#include <bits/stdc++.h>
using namespace std;
string s;
int cl[5005];
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=1;i<=s.size();++i){
        cl[i]+=cl[i-1];
        int l=i;
        int r=i;
        while (l-1>=0 && r-1<s.size() && s[l-1]==s[r-1]) {
            ++cl[r];
            ans+=cl[l-1];
            --l;
            ++r;
        }
        l=i-1;
        r=i;
        while (l-1>=0 && r-1<s.size() && s[l-1]==s[r-1]) {
            ++cl[r];
            ans+=cl[l-1];
            --l;
            ++r;
        }
    }
    cout<<ans;
}