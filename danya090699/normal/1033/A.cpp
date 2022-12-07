#include <bits/stdc++.h>
using namespace std;
const int sz=2e3;
bool us[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    x1--, y1--, x2--, y2--, x3--, y3--;

    queue <pair <int, int> > qu;
    qu.push(make_pair(x2, y2)), us[x2][y2]=1;
    while(qu.size())
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int x=qu.front().first, y=qu.front().second;
            for(int dx=-1; dx<=1; dx++)
            {
                for(int dy=-1; dy<=1; dy++)
                {
                    int nx=x+dx, ny=y+dy;
                    if(nx>=0 and nx<n and ny>=0 and ny<n)
                    {
                        if(nx!=x1 and ny!=y1 and abs(nx-x1)!=abs(ny-y1))
                        {
                            if(us[nx][ny]==0)
                            {
                                us[nx][ny]=1;
                                qu.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
            qu.pop();
        }
    }
    if(us[x3][y3]) cout<<"YES";
    else cout<<"NO";
}