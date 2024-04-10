#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector <int> len;
        int last = -1;
        for(int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                if(x != last)
                {
                        last = x;
                        len.push_back(0);
                }
                len.back()++;
        }
        int r = 0;
        for(int i = 1; i < len.size(); i++)
        {
                r = max(r, 2 * min(len[i - 1], len[i]));
        }
        cout << r << "\n";
        return 0;
}