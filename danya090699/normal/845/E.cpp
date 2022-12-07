//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter multiset <pair <int, int> >::iterator
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, inf=2e9;
    cin>>n>>m>>k;
    int ar[k][2];
    for(int a=0; a<k; a++) cin>>ar[a][0]>>ar[a][1];
    int l=-1, r=1e9+10;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        vector <pair <int, pair <int, pair <int, int> > > > ve;
        for(int a=0; a<k; a++)
        {
            int lg=max(0, ar[a][1]-1-mid);
            int rg=min(m, ar[a][1]+mid);
            int to=max(0, ar[a][0]-1-mid);
            int bo=min(n, ar[a][0]+mid);
            ve.push_back(make_pair(lg, make_pair(0, make_pair(to, bo))));
            ve.push_back(make_pair(rg, make_pair(1, make_pair(to, bo))));
            //if(mid==1) cout<<lg<<" "<<rg<<" "<<to<<" "<<bo<<"\n";
        }
        multiset <pair <int, int> > se;
        se.insert(make_pair(-inf, 0));
        se.insert(make_pair(n, inf));
        int yk=0, pr=0;
        int bl=inf, br=-inf, bt=inf, bb=-inf;
        sort(ve.begin(), ve.end());
        while(yk<ve.size())
        {
            int cu=ve[yk].first;
            //if()
            if(cu>pr)
            {
                for(iter it=se.begin(); it!=se.end(); it++)
                {
                    iter it2=it;
                    it2++;
                    if(it2!=se.end())
                    {
                        int lg=(*it).second, rg=(*it2).first;
                        if(rg>lg)
                        {
                            bl=min(bl, pr);
                            br=max(br, cu);
                            bt=min(bt, lg);
                            bb=max(bb, rg);
                            //if(mid==1) cout<<pr<<" "<<cu<<"\n";
                        }
                    }
                }
            }
            while(yk<ve.size())
            {
                if(cu==ve[yk].first)
                {
                    int lg=ve[yk].second.second.first, rg=ve[yk].second.second.second;
                    if(ve[yk].second.first==0) se.insert(make_pair(lg, rg));
                    else se.erase(se.find(make_pair(lg, rg)));
                    yk++;
                }
                else break;
            }
            pr=cu;
        }
        if(pr<m)
        {
            bl=min(bl, pr);
            br=m, bt=0, bb=n;
        }
        //if(mid==1) cout<<bt<<" "<<bb;
        if(bl==inf) r=mid;
        else
        {
            if(br-bl<=1+mid*2 and bb-bt<=1+mid*2) r=mid;
            else l=mid;
        }
    }
    cout<<r;
}