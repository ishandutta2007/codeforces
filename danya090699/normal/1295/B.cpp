#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, x, su=0, mi=0, ma=0;
        cin>>n>>x;
        string s;
        cin>>s;
        map <int, int> q;
        for(int a=0; a<n; a++)
        {
            q[su]++;
            mi=min(mi, su), ma=max(ma, su);
            if(s[a]=='0') su++;
            else su--;
        }
        if(su==0)
        {
            if(q[x]) printf("-1\n");
            else printf("0\n");
        }
        else
        {
            int d=0;
            if(su>0 and x>ma)
            {
                d=x-ma;
                while(d%su!=0) d++;
            }
            if(su<0 and x<mi)
            {
                d=x-mi;
                while(d%su!=0) d--;
            }
            int an=0;
            while(x>=mi+d and x<=ma+d)
            {
                an+=q[x-d];
                d+=su;
            }
            cout<<an<<"\n";
        }
    }
}