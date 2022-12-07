#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, an;
    cin>>n>>k>>m;
    an=n*m;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int yk=0;
    vector <pair <int, int> > sp;
    while(yk<n)
    {
        int cu=ar[yk], q=0;
        while(yk<n)
        {
            if(ar[yk]==cu)
            {
                q++, yk++;
            }
            else break;
        }
        an-=(q-q%k)*m;
        if(q%k>0)
        {
            if(sp.size()>0)
            {
                if(sp.back().first==cu)
                {
                    sp.back().second+=q%k;
                    if(sp.back().second>=k)
                    {
                        sp.back().second-=k, an-=k*m;
                    }
                }
                else sp.push_back(make_pair(cu, q%k));
            }
            else sp.push_back(make_pair(cu, q%k));
            if(sp.back().second==0) sp.pop_back();
        }
    }
    int n2=sp.size();
    if(n2>0 and m>1)
    {
        int l=0, r=n2-1;
        while(r>l)
        {
            if(sp[l].first==sp[r].first)
            {
                int q=sp[l].second+sp[r].second;
                an-=(q-q%k)*(m-1);
                if(q%k==0)
                {
                    l++, r--;
                }
                else break;
            }
            else break;
        }
        if(l==r)
        {
            int q=sp[l].second*m;
            an-=q-q%k;
            if(q%k==0)
            {
                r--, l++;
                while(r>=0)
                {
                    if(sp[l].first==sp[r].first)
                    {
                        int q2=sp[l].second+sp[r].second;
                        an-=(q2-q2%k);
                        if(q2%k==0)
                        {
                            l++, r--;
                        }
                        else break;
                    }
                    else break;
                }
            }
        }
    }
    cout<<an;
}