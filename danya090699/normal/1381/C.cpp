#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, x, y;
        cin>>n>>x>>y;
        vector <int> sp[n+2];
        int an[n], none, ok=1;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            sp[x].push_back(a);
        }
        vector <pair <int, int> > se;
        for(int a=1; a<=n+1; a++)
        {
            if(sp[a].size())
            {
                se.push_back({sp[a].size(), a});
            }
            else none=a;
        }
        sort(se.begin(), se.end());

        if(se.size()==1)
        {
            int i=se[0].second;
            if(x==y)
            {
                for(int a=0; a<n; a++)
                {
                    if(a<x) an[a]=i;
                    else an[a]=none;
                }
            }
            else ok=0;
        }
        else
        {
            if((se.size()==2 and ((y-x)&1)) or (y-x==1))
            {
                int i1=se[0].second;
                int i2=se[1].second;

                an[sp[i1].back()]=i2, sp[i1].pop_back();
                an[sp[i2].back()]=none, sp[i2].pop_back();
                y--;

                se[0].first--, se[1].first--;
            }

            reverse(se.begin(), se.end());
            while(se.size() and se.back().first==0) se.pop_back();

            int m=y-x, q=0;
            pair <int, int> ar[m];

            while(se.size() and q<m)
            {
                for(int a=se.size()-1; (a>=0 and q<m); a--)
                {
                    int i=se[a].second;
                    ar[q++]={i, sp[i].back()};
                    sp[i].pop_back();
                    se[a].first--;
                    if(se[a].first==0) se.pop_back();
                }
            }

            if(q<m) ok=0;

            if(ok)
            {
                sort(ar, ar+m);
                for(int a=0; a<m; a++)
                {
                    int p=(a+m/2)%m;
                    an[ar[p].second]=ar[a].first;
                    if(ar[p].first==ar[a].first) ok=0;
                }
                for(int a=1; a<=n+1; a++)
                {
                    //cout<<a<<" "<<sp[a].size()<<"\n";
                    while(sp[a].size())
                    {
                        if(x)
                        {
                            an[sp[a].back()]=a;
                            x--;
                        }
                        else an[sp[a].back()]=none;
                        sp[a].pop_back();
                    }
                }
                if(x) ok=0;
            }
        }
        if(ok)
        {
            cout<<"YES\n";
            for(int a=0; a<n; a++) cout<<an[a]<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
}