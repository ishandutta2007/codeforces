            #include <bits/stdc++.h>
            #define int unsigned long long
     
            using namespace std;
            const int M=1e9+7;
            string s;
            int n, ans, dp[1000005], k;
            int p(int x)
            {
                if(x==0 || x==1)
                    return 1;
                if(dp[x])
                    return dp[x];
                dp[x]=(p(x-1)+p(x-2))%M;
                return dp[x];
            }
     
            int32_t main()
            {
                ios_base::sync_with_stdio(0);
                cin.tie(0);
                cout.tie(0);
                cin >> s;
                ans=1;
                n=(int)s.size();
                for(int i=0;i<n;i++)
                {
                    k=0;
                    if(s[i]=='w' || s[i]=='m')
                        ans=0;
                        while(i<n && s[i]=='n')
                        {
                            i++;
                            k++;
                        }
                    if(k)
                        i--;
                    ans=(ans*p(k))%M;
                    k=0;
                    while(i<n && s[i]=='u')
                        {
                            i++;
                            k++;
                        }
                    if(k)
                        i--;
                    ans=(ans*p(k))%M;
                }
                cout << (ans+M)%M;
                return 0;
            }