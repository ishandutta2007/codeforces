#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    int h[n*2], mi=1e9, mq=0;
    h[0]=0;
    for(int a=1; a<=n; a++)
    {
        h[a]=h[a-1];
        if(s[a-1]=='(') h[a]++;
        else h[a]--;
        if(mi>h[a]) mi=h[a], mq=1;
        else if(mi==h[a]) mq++;
    }
    int an=mq, l=1, r=1;
    if(h[n]!=0)
    {
        cout<<"0\n1 1";
        return 0;
    }
    for(int a=n; a<n*2; a++) h[a]=h[a-n];
    int yk=0;
    while(yk<n)
    {
        if(h[yk]==mi)
        {
            int st=yk, q1=0, q2=0, l2=-1;
            yk++;
            while(h[yk]!=mi)
            {
                if(h[yk]==mi+1)
                {
                    q1++;
                    if(mq+q2>an)
                    {
                        an=mq+q2, l=l2, r=(yk-1)%n+1;
                    }
                    l2=yk%n+1, q2=0;
                }
                if(h[yk]==mi+2) q2++;
                yk++;
            }
            if(q1>an)
            {
                an=q1, l=(yk-1)%n+1, r=st+1;
            }
        }
        else yk++;
    }
    cout<<an<<"\n"<<l<<" "<<r;
}