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
        int n;
        cin >> n;
        vector<string> s(n);
        set<int> r,c;
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='*')
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        if(r.size()==1)
        {
            if(*r.begin()==0) r.insert(1);
            else r.insert(0);
        }
        if(c.size()==1)
        {
            if(*c.begin()==0) c.insert(1);
            else c.insert(0);
        }
        for(int a:r) for(int b:c) s[a][b]='*';
        for(int i=0;i<n;i++) cout << s[i] << "\n";
    }
    return 0;
}