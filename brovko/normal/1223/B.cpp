#include <bits/stdc++.h>
using namespace std;
string s, t;
long long k[128], q;
vector <string> ans;

int main()
{
    cin >> q;
    for(int test=0;test<q;test++)
    {
        for(int i=0;i<128;i++)
            k[i]=0;
        cin >> s >> t;
    for(int i=0;i<s.size();i++)
        k[(int)s[i]]++;
    for(int i=0;i<t.size();i++)
        if(k[(int)t[i]])
    {
        ans.push_back("YES");
        for(int i=0;i<128;i++)
            k[i]=0;
    }
    if(ans.size()<=test)
        ans.push_back("NO");
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
    return 0;
}