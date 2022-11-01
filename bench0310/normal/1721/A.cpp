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
        map<char,int> m;
        for(int i=0;i<2;i++)
        {
            string s;
            cin >> s;
            for(char c:s) m[c]++;
        }
        vector<int> v;
        for(auto [a,c]:m) v.push_back(c);
        ranges::sort(v);
        int res=0;
        if(v==vector<int>{1,1,1,1}) res=3;
        if(v==vector<int>{1,1,2}) res=2;
        if(v==vector<int>{2,2}) res=1;
        if(v==vector<int>{1,3}) res=1;
        if(v==vector<int>{4}) res=0;
        cout << res << "\n";
    }
    return 0;
}