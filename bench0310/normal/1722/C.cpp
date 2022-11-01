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
        map<string,int> m;
        vector s(3,vector(n,string()));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> s[i][j];
                m[s[i][j]]++;
            }
        }
        for(int i=0;i<3;i++)
        {
            int c=0;
            for(string a:s[i])
            {
                if(m[a]==1) c+=3;
                if(m[a]==2) c++;
            }
            cout << c << " \n"[i==2];
        }
    }
    return 0;
}