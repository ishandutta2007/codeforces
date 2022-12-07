#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=1;
    cin>>n;
    vector <int> sp[60];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        for(int b=59; b>=0; b--)
        {
            if(x&(1ll<<b))
            {
                sp[b].push_back(x);
                break;
            }
        }
    }
    vector <int> an;
    for(int a=59; a>=0; a--)
    {
        vector <int> an2;
        int ch=0, yk=0, yk2=0;
        while(yk<sp[a].size())
        {
            if(ch)
            {
                if(yk2<an.size())
                {
                    an2.push_back(an[yk2]);
                    if(an[yk2]&(1ll<<a)) ch^=1;
                    yk2++;
                }
                else break;
            }
            else
            {
                an2.push_back(sp[a][yk]), ch^=1, yk++;
            }
        }
        while(yk2<an.size())
        {
            an2.push_back(an[yk2]), yk2++;
        }
        if(yk<sp[a].size())
        {
            ok=0;
            break;
        }
        an.clear();
        for(int b=0; b<an2.size(); b++) an.push_back(an2[b]);
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int a=0; a<n; a++) printf("%lld ", an[a]);
    }
    else cout<<"No";
}