#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef long double ld;

struct point
{
        int x;
        int y;
};

ll permanent(point a,point b)
{
        return (a.x-b.x)*(ll)(a.y+b.y);
}

ll area(point a,point b,point c)
{
        return permanent(a,b)+permanent(b,c)+permanent(c,a);
}

bool kol(point a,point b,point c)
{
        return (area(a,b,c)==0LL);
}

vector<point>p;

bool ok(point a,point b)
{
        vector<point>rz;
        for(auto &it:p)
        {
                if(!kol(a,b,it))
                {
                        rz.push_back(it);
                }
        }
        if(rz.size()<=2)
        {
                return 1;
        }
        for(auto &it:rz)
        {
                if(!kol(rz[0],rz[1],it))
                {
                        return 0;
                }
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);/// cout<<"\n\n";
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                p.push_back({x,y});
        }
        if(n<=4)
        {
                cout<<"YES\n";
                return 0;
        }
      /**  cout<<ok(p[0],p[2])<<"\n";
        return 0;**/
        if(ok(p[0],p[1]) || ok(p[0],p[2]) || ok(p[1],p[2]))
        {
                cout<<"YES\n";
        }
        else
        {
                cout<<"NO\n";
        }
        return 0;
}
/**

5
6 1
10 5
10 -2
-2 -10
-4 -9


**/