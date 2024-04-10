#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k;
string s, x;
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        x="";
        cin >> n >> k;
        cin >> s;
        for(int i=0;i<k-1;i++)
            x+="()";
        int c=(n-x.size())/2;
        for(int i=0;i<c;i++)
            x+="(";
        for(int i=0;i<c;i++)
            x+=")";

        v.erase(v.begin(), v.end());
        for(int i=0;i<n;i++)
        {
            if(s[i]!=x[i])
            {
                int j=i;
                while(s[j]!=x[i])
                    j++;
                v.push_back({i+1, j+1});
                swap(s[i], s[j]);
            }
        }
        cout << v.size() << endl;
        for(auto to:v)
            cout << to.first << ' ' << to.second << endl;
    }
}