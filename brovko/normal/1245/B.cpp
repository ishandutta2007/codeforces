    #include <bits/stdc++.h>
    #define int long long
     
    using namespace std;
    int test, n, a, b, c, ans;
    string s;
    char t[105];
     
    int32_t main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> test;
        for(int i=0;i<test;i++)
        {
            ans=0;
            for(int j=0;j<105;j++)
                t[j]='A';
            cin >> n >> a >> b >> c;
            cin >> s;
            for(int j=0;j<n;j++)
            {
                if(s[j]=='R' && b)
                {
                    ans++;
                    b--;
                    t[j]='P';
                }
                if(s[j]=='P' && c)
                {
                    ans++;
                    c--;
                    t[j]='S';
                }
                if(s[j]=='S' && a)
                {
                    ans++;
                    a--;
                    t[j]='R';
                }
            }
            for(int j=0;j<n;j++)
                if(t[j]=='A')
            {
                if(a)
                {
                    a--;
                    t[j]='R';
                }
                else
                if(b)
                {
                    b--;
                    t[j]='P';
                }
                else
                if(c)
                {
                    c--;
                    t[j]='S';
                }
            }
            if(ans<(n+1)/2)
                cout << "NO\n";
            else
            {
                cout << "YES\n";
                for(int j=0;j<n;j++)
                    cout << t[j];
                cout << "\n";
            }
        }
        return 0;
    }