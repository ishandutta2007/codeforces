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
        array<bool,2> c={0,0};
        for(char a:s) c[a-'0']=1;
        cout << [&]()->int
        {
            if(c[0]==0) return 0;
            else if(c[1]==0) return 1;
            else
            {
                int l=0;
                while(s[l]=='1') l++;
                bool ok=1;
                bool bad=0;
                while(l<n)
                {
                    if(s[l]=='0') ok&=(bad==0);
                    else bad=1;
                    l++;
                }
                return (2-ok);
            }
        }() << "\n";
    }
    return 0;
}