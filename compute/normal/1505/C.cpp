#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<int> all;
    for(int i=0;i<s.length();i++)
        all.push_back(s[i]-'A');
    //for(auto u:all) cout<<u<<" ";
    bool suc=1;
    for(int i=2;i<all.size();i++)
    {
        int psum=all[i-1]+all[i-2];
        if(psum%26!=all[i]) suc=0;
    }
    if(suc) cout<<"YES\n";
    else cout<<"NO\n";
}