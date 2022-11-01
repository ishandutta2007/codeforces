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
        vector<int> c(26,0);
        for(char a:s) c[a-'a']++;
        int res=0;
        int x=0;
        for(int i=0;i<26;i++)
        {
            if(c[i]==1) x++;
            else if(c[i]>=2) res++;
        }
        cout << res+x/2 << "\n";
    }
    return 0;
}