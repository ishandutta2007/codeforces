#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int p, f, cnt1, cnt2, w1, w2, an=0;
        cin>>p>>f>>cnt1>>cnt2>>w1>>w2;

        if(w1>w2) swap(w1, w2), swap(cnt1, cnt2);

        for(int a=0; a<=cnt1 and a*w1<=p; a++)
        {
            int q1=p-a*w1, q2=f, c1=cnt1-a, c2=cnt2;

            int t=min(c2, q1/w2);
            q1-=t*w2, c2-=t;

            t=min(c1, q2/w1), q2-=t*w1, c1-=t;

            t=min(c2, q2/w2), q2-=t*w2, c2-=t;

            an=max(an, cnt1-c1+cnt2-c2);
        }
        cout<<an<<"\n";
    }
}