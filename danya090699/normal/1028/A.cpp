#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, lx=1e9, rx=-1e9, ly=1e9, ry=-1e9;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            char sy;
            cin>>sy;
            if(sy=='B')
            {
                lx=min(lx, a), rx=max(rx, a), ly=min(ly, b), ry=max(ry, b);
            }
        }
    }
    cout<<(lx+rx)/2+1<<" "<<(ly+ry)/2+1;
}