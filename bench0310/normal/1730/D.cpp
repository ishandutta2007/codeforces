#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        map<string,int> m;
        string s,t;
        cin >> s >> t;
        for(int i=0;i<n;i++)
        {
            string a=s.substr(i,1)+t.substr(n-1-i,1);
            ranges::sort(a);
            m[a]++;
        }
        int odd=0;
        string o;
        for(auto [a,c]:m)
        {
            odd+=(c&1);
            if(c&1) o=a;
        }
        bool res=0;
        if((n%2)==0) res=(odd==0);
        else res=(odd==1&&o[0]==o[1]);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}