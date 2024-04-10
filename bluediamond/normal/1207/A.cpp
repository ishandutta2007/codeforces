#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;
        while(q--)
        {

        int b,p,f;
        int h,c;
        cin>>b>>p>>f>>h>>c;
        int ans=0,t;
        b/=2;
        if(h>c)
        {
                t=min(b,p);
                b-=t;
                p-=t;
                ans+=t*h;

                t=min(b,f);
                b-=t;
                f-=t;
                ans+=t*c;
        }
        else
        {
                t=min(b,f);
                b-=t;
                f-=t;
                ans+=t*c;

                t=min(b,p);
                b-=t;
                p-=t;
                ans+=t*h;
        }
        cout<<ans<<"\n";
        }
        return 0;
}