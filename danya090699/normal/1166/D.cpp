#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int x, y, m, fo=0, r[60];
        cin>>x>>y>>m;
        for(int a=0; a<50; a++)
        {
            int st=max(a-1, 0ll);
            if(y/x>=(1ll<<st))
            {
                int le=y-(1ll<<st)*x;
                for(int b=a; b>=1; b--)
                {
                    int st=max(0ll, a-b-1);
                    le-=(1ll<<st);
                }
                if(le>=0)
                {
                    for(int b=1; b<=a; b++)
                    {
                        int st=max(0ll, a-b-1), q=min(m-1, le/(1ll<<st));
                        le-=q*(1ll<<st), r[b]=q+1;
                    }
                }

                if(le==0)
                {
                    fo=1;
                    int an[a+1];
                    an[0]=x;
                    for(int b=1; b<=a; b++)
                    {
                        an[b]=r[b];
                        for(int c=0; c<b; c++) an[b]+=an[c];
                    }
                    cout<<a+1<<" ";
                    for(int b=0; b<=a; b++) cout<<an[b]<<" ";
                    cout<<"\n";
                    break;
                }
            }
        }
        if(fo==0) cout<<"-1\n";
    }
}