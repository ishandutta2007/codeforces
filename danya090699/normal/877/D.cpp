#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    char fi[n][m];
    int le[n][m];
    set <int> go[n], ve[m];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            cin>>fi[a][b];
            le[a][b]=-1;
            go[a].insert(b), ve[b].insert(a);
        }
    }
    int x1, y1, x2, y2, lev=1;
    cin>>x1>>y1>>x2>>y2;
    x1--, y1--, x2--, y2--;
    go[x1].erase(y1), ve[y1].erase(x1);
    le[x1][y1]=0;
    queue <pair <int, int> > qu;
    qu.push(make_pair(x1, y1));
    while(qu.size()>0)
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int x=qu.front().first, y=qu.front().second;
            while(1)
            {
                iter it=go[x].lower_bound(y);
                if(it==go[x].begin()) break;
                it--;
                int cy=*it;
                if(cy<y-k or fi[x][cy]=='#') break;
                else
                {
                    go[x].erase(cy), ve[cy].erase(x);
                    le[x][cy]=lev;
                    qu.push(make_pair(x, cy));
                }
            }
            while(1)
            {
                iter it=go[x].lower_bound(y);
                if(it==go[x].end()) break;
                int cy=*it;
                if(cy>y+k or fi[x][cy]=='#') break;
                else
                {
                    go[x].erase(cy), ve[cy].erase(x);
                    le[x][cy]=lev;
                    qu.push(make_pair(x, cy));
                }
            }
            while(1)
            {
                iter it=ve[y].lower_bound(x);
                if(it==ve[y].begin()) break;
                it--;
                int cx=*it;
                if(cx<x-k or fi[cx][y]=='#') break;
                else
                {
                    ve[y].erase(cx), go[cx].erase(y);
                    le[cx][y]=lev;
                    qu.push(make_pair(cx, y));
                }
            }
            while(1)
            {
                iter it=ve[y].lower_bound(x);
                if(it==ve[y].end()) break;
                int cx=*it;
                if(cx>x+k or fi[cx][y]=='#') break;
                else
                {
                    ve[y].erase(cx), go[cx].erase(y);
                    le[cx][y]=lev;
                    qu.push(make_pair(cx, y));
                }
            }
            qu.pop();
        }
        lev++;
    }
    cout<<le[x2][y2];
}