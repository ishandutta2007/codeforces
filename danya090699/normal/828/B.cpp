//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int x1=1e9, x2=-1, y1=1e9, y2=-1, bq=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            char sy;
            cin>>sy;
            if(sy=='B')
            {
                x1=min(x1, b), x2=max(x2, b);
                y1=min(y1, a), y2=max(y2, a);
                bq++;
            }
        }
    }
    int h, w;
    if(x2==-1)
    {
        h=1, w=1;
    }
    else
    {
        h=y2-y1+1, w=x2-x1+1;
    }
    int l=max(h, w);
    if(n>=l and m>=l) cout<<(l*l)-bq;
    else cout<<-1;
}