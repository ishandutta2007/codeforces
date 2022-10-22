#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin>>t;
    while (t--)
    {
        vector<int> pos;
        string s;
        cin>>s;
        pos.push_back(0);
        for (int x = 0; x < s.length(); x++)
            if (s[x] == 'R')
                pos.push_back(x+1);
        pos.push_back(s.length()+1);
        int ma = INT_MIN;
        for (int x = 0; x < pos.size()-1; x++)
            ma = max(ma, pos[x+1] - pos[x]);
        printf("%i\n", ma);
    }
}