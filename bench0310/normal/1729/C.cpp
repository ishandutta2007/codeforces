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
        string s;
        cin >> s;
        int n=s.size();
        if(s[0]>s[n-1]) for(char &c:s) c=('a'+'z'-c);
        vector<int> v[26];
        for(int i=0;i<n;i++) v[s[i]-'a'].push_back(i);
        vector<int> res;
        for(char c=s[0];c<=s[n-1];c++) for(int x:v[c-'a']) res.push_back(x);
        cout << int(s[n-1]-s[0]) << " " << res.size() << "\n";
        for(int x:res) cout << x+1 << " ";
        cout << "\n";
    }
    return 0;
}