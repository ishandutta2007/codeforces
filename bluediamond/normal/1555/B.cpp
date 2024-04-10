#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int INF=(int) 1e18;
int h, w, x1, y1, x2, y2, h2, w2, sol;


bool ok(int px, int py)
{
        int xmin=min(x1, x2), xmax=max(x1, x2);
        int ymin=min(y1, y2), ymax=max(y1, y2);
        xmin+=px, xmax+=px;
        ymin+=py, ymax+=py;
        return 0<=xmin&&0<=ymin&&xmax<=w&&ymax<=h;
}

void relax(int px, int py)
{
        assert(px==0||py==0);
        if (ok(px, py))
        {
                sol=min(sol, px+py);
        }
}

void colt1()
{
        int xmin=min(x1, x2), xmax=max(x1, x2);
        int ymin=min(y1, y2), ymax=max(y1, y2);
      //  cout<<w2<<" and "<<h2<<"\n";
      //  cout<<xmin<<" and "<<ymin<<"\n";
        if (xmin<w2) relax(w2-xmin, 0); else relax(0, 0);
        if (ymin<h2) relax(0, h2-ymin); else relax(0, 0);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      //  freopen ("input", "r", stdin);


        int t;
        cin>>t;
        while (t--)
        {
                sol=INF;
                cin>>w>>h>>x1>>y1>>x2>>y2>>w2>>h2;
                /// in unul din colturi



                /// colt 1
                /// trebuie sa facem xmin>=w2 sau ymin>=h2


                for (int rx=0; rx<=1; rx++)
                {
                        for (int ry=0; ry<=1; ry++)
                        {
                                if (rx) x1=w-x1, x2=w-x2;
                                if (ry) y1=h-y1, y2=h-y2;
                                colt1();

                               /** if (sol==0)
                                {
                                        cout<<" = "<<rx<<" and "<<ry<<"\n";
                                        return 0;
                                }**/

                                if (rx) x1=w-x1, x2=w-x2;
                                if (ry) y1=h-y1, y2=h-y2;
                        }
                }

                if (sol==INF)
                {
                        cout<<"-1\n";
                }
                else
                {
                        cout<<sol<<".000000000\n";

                }
        }

}