            #include <bits/stdc++.h>
            #define int long long
             
            using namespace std;
            int t, a[200005], n, Min, k[200005];
            vector <int> g[200005];
             
            int32_t main()
            {
                ios_base::sync_with_stdio(0);
                cin.tie(0);
                cout.tie(0);
                cin >> t;
                for(int tt=0;tt<t;tt++)
                {
                    Min=1ll*1e18;
                    cin >> n;
                    for(int i=0;i<n;i++)
                        {
                            cin >> a[i];
                            g[a[i]].push_back(i);
                        }
                    for(int i=0;i<n;i++){
                        for(int j=k[a[i]]+1;j<g[a[i]].size();j++)
                        {
                        Min=min(Min, g[a[i]][j]-g[a[i]][j-1]+1);
                        }
                        k[a[i]]=g[a[i]].size();
                    }
                    if(Min==1ll*1e18)
                        cout << "-1\n";
                    else cout << Min << "\n";
                }
                return 0;
            }