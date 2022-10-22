#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, k, c[128];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> s;
        int ans=0;
        for(int i=0;i<(k+1)/2;i++)
        {
            for(int p='a';p<='z';p++)
                c[p]=0;
            for(int j=0;j<n;j+=k)
            {
                c[s[j+i]]++;
                c[s[j+k-i-1]]++;
            }

            int Max='a';
            for(int p='a';p<='z';p++)
                if(c[p]>c[Max])
                    Max=p;

            if(k%2!=0 && i==k/2)
                ans+=c[Max]/2;
            else ans+=c[Max];
        }

        cout << n-ans << endl;
    }
}