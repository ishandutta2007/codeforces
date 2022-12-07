#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, n=0;
    cin>>x>>y;
    int q[10];
    for(int a=0; a<10; a++) q[a]=0;
    while(x)
    {
        q[x%10]++, x/=10, n++;
    }
    int an[n], re=0;
    for(int a=0; a<n; a++)
    {
        for(int b=9; b>=0; b--)
        {
            if(q[b])
            {
                q[b]--;
                int st=1, add=0;
                for(int c=9; c>=0; c--)
                {
                    for(int d=0; d<q[c]; d++)
                    {
                        add+=c*st, st*=10;
                    }
                }
                if(re+b*st+add<=y)
                {
                    an[a]=b, re+=b*st;
                    break;
                }
                else q[b]++;
            }
        }
    }
    for(int a=0; a<n; a++) cout<<an[a];
}