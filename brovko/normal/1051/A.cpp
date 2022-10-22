#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;
string s;

int f(char c)
{
    if(c>='a' && c<='z')
        return 0;
    if(c>='A' && c<='Z')
        return 1;
    return 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> s;
        int n=s.size();

        int a[3];
        a[0]=0;
        a[1]=0;
        a[2]=0;

        for(int i=0;i<n;i++)
        {
            a[f(s[i])]=1;
        }

        if(a[0]+a[1]+a[2]==3)
            cout << s;
        else
        {
            if(a[0]+a[1]+a[2]==1)
            {
                if(a[0]==1)
                    cout << "A1";
                if(a[1]==1)
                    cout << "a1";
                if(a[2]==1)
                    cout << "aA";
                for(int i=2;i<n;i++)
                    cout << s[i];
            }
            else
            {
                int x=0;
                if(f(s[1])==f(s[2]))
                    x=1;
                char c;
                if(a[0]==0)
                    c='a';
                else if(a[1]==0)
                    c='A';
                else c='1';

                for(int i=0;i<n;i++)
                    if(i==x)
                        cout << c;
                    else cout << s[i];
            }
        }
        cout << endl;
    }
}