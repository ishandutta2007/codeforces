#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int n, k, f, p;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s >> p;
    n=s.size();

    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
            k++;
        else if(s[i]=='*')
            f=1;
    }

    int c=n-2*(n-k);

    if(p<c || (p>k && f==0))
    {
        cout << "Impossible";
        return 0;
    }

    s+='a';

    for(int i=0;i<n;i++)
    {
        if(isalpha(s[i]) && isalpha(s[i+1]))
            cout << s[i];
        if(s[i+1]=='?')
        {
            if(k<=p)
                cout << s[i];
            else k--;
        }

        if(s[i+1]=='*')
        {
            if(k==p)
                cout << s[i];
            else if(k<p)
            {
                cout << s[i];
                while(k<p)
                {
                    k++;
                    cout << s[i];
                }
            }
            else k--;
        }
    }
}