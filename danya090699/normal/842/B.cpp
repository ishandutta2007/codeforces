//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int r, d, n, q=0;
    cin>>r>>d>>n;
    for(int a=0; a<n; a++)
    {
        int x, y, cr;
        scanf("%d%d%d", &x, &y, &cr);
        int di=x*x+y*y;
        if(cr<=r)
        {
            //if(a==3) cout<<di;
            if(di>=(r-d+cr)*(r-d+cr) and di<=(r-cr)*(r-cr))
            {
                q++;
                //cout<<a+1<<" ";
            }
        }
    }
    cout<<q;
}