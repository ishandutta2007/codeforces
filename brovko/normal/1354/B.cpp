#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

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
        int Min=1e9;
        int b[4];
        for(int i=0;i<4;i++)
            b[i]=0;

        int R=0;
        for(int L=0;L<n;L++)
        {
            while(R<=L)
            {
                b[s[R]-'0']++;
                R++;
            }

            while(R<n && !(b[1]>0 && b[2]>0 && b[3]>0))
            {
                b[s[R]-'0']++;
                R++;
            }

            if(b[1]>0 && b[2]>0 && b[3]>0)
                Min=min(Min, R-L);
            b[s[L]-'0']--;
        }

        if(Min==1e9)
            cout << "0\n";
        else cout << Min << "\n";
    }
}