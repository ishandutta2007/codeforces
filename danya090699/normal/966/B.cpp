#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x1, x2;
    cin>>n>>x1>>x2;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a].first);
        ar[a].second=a+1;
    }
    sort(ar, ar+n);
    int mi1=n+1, mi2=n+1;
    for(int a=n-1; a>=0; a--)
    {
        if(ar[a].first*(n-a)>=x1)
        {
            mi1=(n-a);
            break;
        }
    }
    for(int a=n-1; a>=0; a--)
    {
        if(ar[a].first*(n-a)>=x2)
        {
            mi2=(n-a);
            break;
        }
    }
    vector <int> sp1, sp2;
    for(int a=0; a<n; a++)
    {
        if(sp1.size()==0)
        {
            int q=de(x1, ar[a].first);
            if(a+q+mi2<=n)
            {
                for(int b=a; b<a+q; b++) sp1.push_back(ar[b].second);
                for(int b=n-1; b>=n-mi2; b--) sp2.push_back(ar[b].second);
                break;
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        if(sp1.size()==0)
        {
            int q=de(x2, ar[a].first);
            if(a+q+mi1<=n)
            {
                for(int b=a; b<a+q; b++) sp2.push_back(ar[b].second);
                for(int b=n-1; b>=n-mi1; b--) sp1.push_back(ar[b].second);
                break;
            }
        }
    }
    if(sp1.size())
    {
        cout<<"Yes\n"<<sp1.size()<<" "<<sp2.size()<<"\n";
        for(int a=0; a<sp1.size(); a++) printf("%lld ", sp1[a]);
        cout<<"\n";
        for(int a=0; a<sp2.size(); a++) printf("%lld ", sp2[a]);
    }
    else cout<<"No";
}