#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>

using namespace std;
int n,k,w,a[5555],q,x,X;
short int ans;
pair <int, short int> p[100009];
map<int, pair <int, short int> > b;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        for (int j=1; j<=k; j++)
        {
            if (b[a[i]*j].second==0)
            {
                //b[a[i]*j][0]++;
                w++;
                p[w]=make_pair(a[i]*j,j);
                b[a[i]*j].first=w;
                b[a[i]*j].second=j;
            }
            else
            {
                p[b[a[i]*j].first].second=min(b[a[i]*j].first,j);
            }
        }
    }
    sort(p+1,p+w+1);
    /*for (int i=1; i<=w; i++)
    {
        cout << p[i].first << ' ' << p[i].second << endl;
    }*/

    cin >> q;
    for (int i=0; i<q; i++)
    {
        cin >> x;
        ans=-1;
        for (int j=1; j<=w; j++)
        {
            if (p[j].first==x)
            {
                if (ans==-1) ans=p[j].second;
                else ans=min(ans,p[j].second);
            }
            if (p[j].first<x)
            {
                X=x-p[j].first;
                int r,l,m;
                r=w-1;
                l=1;
                while (r-l>1)
                {
                    m=(l+r) / 2;
                    if (X>p[m].first) l=m;
                    else r=m;
                }
                if (p[r].first==X && p[j].second+p[r].second<=k)
                {
                    short int h=p[j].second+p[r].second;
                    if (ans==-1) ans=h;
                    else ans=min(ans,h);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}