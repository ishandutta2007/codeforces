#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string an;
        int n, k;
        cin>>n>>k;
        for(int i=0; i<10; i++)
        {
            for(int q=0; q*9<=n; q++)
            {
                int su=0;
                for(int x=i; x<=i+k; x++)
                {
                    if(x<10) su+=q*9;
                    else su++;

                    su+=x%10;
                }
                if(su<=n and (n-su)%(k+1)==0)
                {
                    int lef=(n-su)/(k+1);
                    string s;
                    while(lef)
                    {
                        int mx=9;
                        if(s.size()==0) mx=8;
                        int zi=min(lef, mx);
                        lef-=zi;
                        s.push_back('0'+zi);
                    }
                    reverse(s.begin(), s.end());
                    for(int a=0; a<q; a++) s.push_back('9');
                    s.push_back('0'+i);

                    if(an.size()==0 or s.size()<an.size() or (s.size()==an.size() and s<an)) an=s;
                }
            }
        }
        if(an.size()) cout<<an<<"\n";
        else cout<<"-1\n";
    }
}