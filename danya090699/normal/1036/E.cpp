#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, inf=1e9;
    cin>>n;
    int ot[n][4];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<4; b++) cin>>ot[a][b];
        int x1=ot[a][0], y1=ot[a][1], x2=ot[a][2], y2=ot[a][3];
        an+=__gcd(abs(x1-x2), abs(y1-y2))+1;
    }
    map <int, set <int> > ma;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            int x1=ot[a][0], y1=ot[a][1], x2=ot[a][2], y2=ot[a][3];
            int x3=ot[b][0], y3=ot[b][1], x4=ot[b][2], y4=ot[b][3];

            int a1=y2-y1, b1=x1-x2, c1;
            c1=-a1*x1-b1*y1;
            int a2=y4-y3, b2=x3-x4, c2;
            c2=-a2*x3-b2*y3;

            if((a1*b2-a2*b1)!=0)
            {
                int chx=-c1*b2+c2*b1, znx=a1*b2-a2*b1;
                int chy=-c1*a2+c2*a1, zny=b1*a2-b2*a1;
                if(abs(chx)%abs(znx)==0 and abs(chy)%abs(zny)==0)
                {
                    int x=chx/znx, y=chy/zny;
                    if(x>=min(x1, x2) and x<=max(x1, x2) and y>=min(y1, y2) and y<=max(y1, y2) and x>=min(x3, x4) and x<=max(x3, x4) and y>=min(y3, y4) and y<=max(y3, y4))
                    {
                        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"  "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n\n";

                        //cout<<x<<" "<<y<<"\n\n";
                        ma[x*inf+y].insert(a);
                        ma[x*inf+y].insert(b);
                    }
                }
            }
        }
    }
    for(auto it=ma.begin(); it!=ma.end(); it++) an-=(*it).second.size()-1;
    cout<<an;
}