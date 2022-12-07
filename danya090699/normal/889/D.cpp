#include <bits/stdc++.h>
#define int long long
using namespace std;
struct dr
{
    int ch, zn;
    bool operator == (const dr& x) const {return (ch==x.ch and zn==x.zn);}
    bool operator < (const dr& x) const
    {
        if(ch!=x.ch) return ch<x.ch;
        else return zn<x.zn;
    }
};
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
void norm(dr& x)
{
    if(x.ch==0) x.zn=1;
    else if(x.zn==0) x.ch=1;
    else
    {
        if(x.zn<0)
        {
            x.ch*=-1, x.zn*=-1;
        }
        int x2=__gcd(mo(x.ch), x.zn);
        x.ch/=x2, x.zn/=x2;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2], good[n];
    dr xce={0, n}, yce={0, n};
    for(int a=0; a<n; a++)
    {
        good[a]=0;
        cin>>ar[a][0]>>ar[a][1];
        ar[a][0]*=2, ar[a][1]*=2;
        xce.ch+=ar[a][0], yce.ch+=ar[a][1];
    }
    int q=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            int x=(ar[a][0]+ar[b][0])/2, y=(ar[a][1]+ar[b][1])/2;
            if(xce.ch==(x*xce.zn) and yce.ch==(y*yce.zn))
            {
                good[a]=1, q++;
                break;
            }
        }
    }
    if(q==n) cout<<-1;
    else
    {
        int an=0;
        set <dr> us;
        for(int a=0; a<n; a++)
        {
            if(good[a]==0)
            {
                for(int b=0; b<n; b++)
                {
                        int x=(ar[a][0]+ar[b][0])/2, y=(ar[a][1]+ar[b][1])/2;
                            dr vx={x*xce.zn-xce.ch, xce.zn}, vy={y*yce.zn-yce.ch, yce.zn};
                            dr vec={vx.ch*vy.zn, vx.zn*vy.ch};
                            norm(vec);
                                if(us.find(vec)==us.end())
                                {
                                    us.insert(vec);
                                    map <dr, int> pl, mi;
                                    if(vec.ch!=0)
                                    {
                                        for(int c=0; c<n; c++)
                                        {
                                            dr vy2={(x-ar[c][0])*vec.zn, vec.ch};
                                            dr y2={ar[c][1]*vy2.zn+vy2.ch, vy2.zn};
                                            dr di={y*y2.zn-y2.ch, y2.zn};
                                            norm(di);
                                            if(di.ch>0) pl[di]++;
                                            if(di.ch<0)
                                            {
                                                di.ch*=-1;
                                                mi[di]++;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        for(int c=0; c<n; c++)
                                        {
                                            dr di={x-ar[c][0], 1};
                                            if(di.ch>0) pl[di]++;
                                            if(di.ch<0)
                                            {
                                                di.ch*=-1;
                                                mi[di]++;
                                            }
                                        }
                                    }
                                    if(pl.size()==mi.size())
                                    {
                                        map <dr, int>::iterator it=pl.begin(), it2=mi.begin();
                                        bool ok=1;
                                        while(it!=pl.end())
                                        {
                                            int qq1=(*it).second, qq2=(*it2).second;
                                            dr p1=(*it).first, p2=(*it2).first;
                                            if(p1.ch!=p2.ch or p1.zn!=p2.zn or qq1!=qq2) ok=0;
                                            it++, it2++;
                                        }
                                        an+=ok;
                                    }
                                }
                }
                break;
            }

        }
        cout<<an;
    }
}