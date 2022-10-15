#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int f[26];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        for(auto &ch:s)
                f[ch-'A']++;
        vector<int>u;
        for(int i=0;i<26;i++)
                u.push_back(f[i]);
        sort(u.rbegin(),u.rend());
        ll ss=0;
        for(auto &it:u)
        {
                int t=min(x,it);
                x-=t;
                ss+=t*(ll)t;
        }
        cout<<ss<<"\n";
        return 0;
}