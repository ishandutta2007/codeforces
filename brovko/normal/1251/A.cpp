#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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
        int n=s.size();
        int used[128];
        for(int i=0;i<128;i++)
            used[i]=0;

        int k=1;
        for(int i=1;i<n;i++)
            {
                if(s[i]==s[i-1])
                    k++;
                else
                {
                    if(k%2)
                        used[s[i-1]]=1;
                    k=1;
                }
            }
        if(k%2)
            used[s[n-1]]=1;

        for(int i=0;i<128;i++)
            if(used[i])
                cout << (char)i;
        cout << "\n";
    }
}