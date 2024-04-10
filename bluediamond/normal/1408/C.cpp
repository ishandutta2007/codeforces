#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int t;
        cin>>t;
        while (t--)
        {
                int n;
                ld a=0,b,va=1,vb=1,t=0;
                cin>>n>>b;
                deque<ld> x;
                for (int i=1;i<=n;i++)
                {
                        int pz;
                        cin>>pz;
                        x.push_back(pz);
                }
                while (!x.empty())
                {
                        ld t1=(x.front()-a)/va;
                        ld t2=(b-x.back())/vb;
                        ld delta_t=t;
                        t+=min(t1,t2);
                        delta_t=t-delta_t;
                        a+=delta_t*va;
                        b-=delta_t*vb;
                        if (t1<t2)
                        {
                                va++;
                                x.pop_front();
                        }
                        else
                        {
                                vb++;
                                x.pop_back();
                        }
                }
                t+=(b-a)/(va+vb);
                cout<<fixed<<setprecision(6)<<t<<"\n";
        }
}