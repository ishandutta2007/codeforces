#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
	//freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sp[n+1], co[n+1];
    for(int a=0; a<n; a++)
    {
        int s;
        cin>>s;
        s--, sp[s].push_back(a);
    }
    for(int a=0; a<m; a++)
    {
        int f, h;
        cin>>f>>h;
        f--, co[f].push_back(h);
    }
    for(int a=0; a<n; a++) sort(co[a].begin(), co[a].end());
    co[n].push_back(0);

    int an=0, anq=1;

    for(int a=0; a<=n; a++)
    {
        for(int b=0; (b<co[a].size() and co[a][b]<=sp[a].size()); b++)
        {
            int su, q=1, p;

            if(a<n)
            {
                su=1, p=sp[a][co[a][b]-1];
                int r=0;
                while(r<co[a].size() and co[a][r]<=sp[a].size()-co[a][b]) r++;
                if(b<r) r--;
                //cout<<r<<" ";
                if(r) su++, q*=r;
            }
            else
            {
                su=0, p=-1;
            }
            //cout<<a<<" "<<p<<" "<<su<<"\n";
            for(int c=0; c<n; c++)
            {
                if(c!=a)
                {
                    int lq=0, rq=sp[c].size();
                    while(lq<sp[c].size() and sp[c][lq]<p) lq++, rq--;
                    if(lq>rq) swap(lq, rq);

                    int l=0, r=0;
                    for(int d=0; d<co[c].size(); d++)
                    {
                        if(co[c][d]<=lq) l++;
                        if(co[c][d]<=rq) r++;
                    }
                    //if(p==-1 and c==0) cout<<l<<" "<<r;
                    if(r)
                    {
                        if(l==0) su++, q=1ll*q*r%mod;
                        else
                        {
                            if(r==1) su++, q=2ll*q%mod;
                            else
                            {
                                su+=2, q=1ll*q*l*(r-1)%mod;
                            }
                        }
                    }
                }
            }

            //cout<<a<<" "<<p<<" "<<su<<"\n";

            if(su>an) an=su, anq=q;
            else if(su==an) anq=(anq+q)%mod;
        }
    }
    if(an==0) anq=1;
    cout<<an<<" "<<anq;
}