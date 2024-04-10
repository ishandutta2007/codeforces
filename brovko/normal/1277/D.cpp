#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int t, n;
string s[200005];

int32_t main()
{
    cin >> t;
    while(t--)
    {
        int k[2][2];
        k[0][0]=0;
        k[0][1]=0;
        k[1][0]=0;
        k[1][1]=0;
        int f=0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            k[s[i][0]-'0'][s[i][s[i].size()-1]-'0']++;
        }
        if(k[0][1]+k[1][0]==0 && k[0][0]*k[1][1]!=0)
            f=1;

        map <string, int> m;
        for(int i=0;i<n;i++)
            m[s[i]]=1;
        vector <int> ans;

        for(int i=0;i<n;i++)
            if(s[i][0]-'0' + s[i][s[i].size()-1]-'0' == 1 && k[s[i][0]-'0'] [s[i][s[i].size()-1]-'0'] > k[s[i][s[i].size()-1]-'0'] [s[i][0]-'0']+1)
        {
            int z=s[i].size();
            for(int j=0;j<z/2;j++)
                swap(s[i][j], s[i][z-1-j]);
            if(m[s[i]]==0)
            {
                ans.pb(i+1);
                k[s[i][0]-'0'] [s[i][s[i].size()-1]-'0'] ++;
                k[s[i][s[i].size()-1]-'0'] [s[i][0]-'0'] --;
            }

        }
        if(f)
            cout << -1 << endl;
        else
        {
            cout << ans.size() << endl;
            for(auto to:ans)
                cout << to << ' ';
            cout << endl;
        }
    }
}