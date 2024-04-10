#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t=1;
        while (t--)
        {
                int n,sol=0;
                ll c=0;
                set<ll> s;
                s.insert(0);
                cin>>n;
                for (int i=1;i<=n;i++)
                {
                        int x;
                        cin>>x;
                        c+=x;
                        if (s.count(c))
                        {
                                sol++;
                                s.clear();
                                c=x;
                                s.insert(0);
                                s.insert(c);
                        }
                        else
                        {
                                s.insert(c);
                        }
                }
                cout<<sol<<"\n";
        }

}