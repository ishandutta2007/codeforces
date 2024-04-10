#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string k;
        cin >> k;
        vector<int> h(26,-1);
        for(int i=0;i<26;i++) h[k[i]-'a']=i;
        int res=0;
        string s;
        cin >> s;
        int n=s.size();
        for(int i=0;i+1<n;i++) res+=abs(h[s[i]-'a']-h[s[i+1]-'a']);
        cout << res << "\n";
    }
    return 0;
}