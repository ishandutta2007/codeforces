#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        int l[128], r[128], used[128];
        for(int i=0;i<128;i++)
        {
            l[i]=0;
            r[i]=0;
            used[i]=0;
        }
        int f=1;

        used[s[0]]=1;

        for(int i=1;i<s.size();i++)
        {
            if(used[s[i]]==1 && l[s[i-1]]!=s[i] && r[s[i-1]]!=s[i])
            {
                f=0;
            }
            else
            if(used[s[i]]==0)
            {
                if(l[s[i-1]]==0)
                {
                    l[s[i-1]]=s[i];
                    r[s[i]]=s[i-1];
                    used[s[i]]=1;
                }
                else
                if(r[s[i-1]]==0)
                {
                    r[s[i-1]]=s[i];
                    l[s[i]]=s[i-1];
                    used[s[i]]=1;
                }
                else f=0;
            }
        }

        if(f==0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            char c=s[0];
            while(l[c]!=0)
                {
                    c=l[c];
                }

            while(c!=0)
            {
                cout << c;
                c=r[c];
            }
            for(int i='a';i<='z';i++)
                if(used[i]==0)
                cout << (char)i;
            cout << endl;
        }
    }
}