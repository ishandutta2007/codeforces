#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int q, n=0;
    cin>>q;
    int zap[q][3];
    map <pair <int, int>, int> pairs, points;
    map <long long, set <pair <int, int> > > ma;
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &zap[a][b]);
        int x=zap[a][1], y=zap[a][2];
        int d=__gcd(x, y);
        if(zap[a][0]==3)
        {
            pairs[make_pair(x/d, y/d)]=0;
            points[make_pair(x/d, y/d)]=0;
        }
        else ma[1ll*x*x+1ll*y*y];
    }
    for(int a=0; a<q; a++)
    {
        int ty=zap[a][0], x=zap[a][1], y=zap[a][2];
        if(ty==1 or ty==2)
        {
            set <pair <int, int> > &cu=ma[1ll*x*x+1ll*y*y];

            for(auto it=cu.begin(); it!=cu.end(); it++)
            {
                int x2=(*it).first, y2=(*it).second;
                int vx=abs(x-x2), vy=abs(y-y2);
                if(!(vx==0 and vy==0))
                {
                    int d=__gcd(vx, vy);
                    auto it2=pairs.find(make_pair(vy/d, vx/d));
                    if(it2!=pairs.end())
                    {
                        if(ty==1) (*it2).second++;
                        else (*it2).second--;
                    }
                }
            }
            if(ty==1) cu.insert(make_pair(x, y));
            else cu.erase(make_pair(x, y));

            int d=__gcd(x, y);
            auto it=points.find(make_pair(x/d, y/d));
            if(it!=points.end())
            {
                if(ty==1) (*it).second++;
                else (*it).second--;
            }

            if(ty==1) n++;
            if(ty==2) n--;
        }
        else
        {
            int d=__gcd(x, y);
            x/=d, y/=d;
            int an=n-pairs[make_pair(x, y)]*2-points[make_pair(x, y)];
            printf("%d\n", an);
        }
    }
}