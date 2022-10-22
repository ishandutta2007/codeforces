#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

string s;

void sh(int i)
{
    if(s[i]=='W')
        s[i]='B';
    else
        s[i]='W';
    if(s[i+1]=='W')
        s[i+1]='B';
    else
        s[i+1]='W';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen(".in","r",stdin);

    int n;
    cin >> n;
    cin >> s;
    int c0=0,c1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W')
            c0++;
        else
            c1++;
    }

    if(c0&1 && c1&1)
        db(-1)
    else
    {
        vector<int> res;
        if((c0&1)==0)
        {
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='W')
                {
                    sh(i);
                    res.push_back(i+1);
                }
            }
        }
        else
        {
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='B')
                {
                    sh(i);
                    res.push_back(i+1);
                }
            }
        }
        db(res.size())
        for(auto y : res)
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}