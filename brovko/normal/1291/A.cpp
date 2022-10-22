    #include <bits/stdc++.h>
    #define int long long
    #define pb push_back

    using namespace std;

    int t, n, a[3005];

    int32_t main()
    {
        cin >> t;
        while(t--)
        {
            cin >> n;
            int f=0;
            int s=0;
            for(int i=0;i<n;i++)
            {
                char c;
                cin >> c;
                a[i]=c-'0';
                if(a[i]%2)
                    f++;
                s+=a[i];
            }

            if(f<=1)
                cout << -1 << endl;
            else
            {
                int l=0;
                int r=n-1;
                while(a[r]%2==0)
                    r--;
                if(s%2)
                    while(a[l]%2==0)
                        l++;
                if(s%2)
                    {
                        l++;
                        while(a[l]%2==0)
                            l++;
                    }
                for(int i=l;i<=r;i++)
                    cout << a[i];
                cout << endl;
            }
        }
    }