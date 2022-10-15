#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mt[8][3];

ll fk(ll a,ll b)
{
        ll d=a-b;
        return d*d;
}

ll fk(ll a,ll b,ll i,ll j)
{
        return fk(mt[a][i],mt[b][j]);
}

ll calc(ll a,ll b,ll i1,ll i2,ll i3,ll j1,ll j2,ll j3)
{
        return fk(a,b,i1,j1)+fk(a,b,i2,j2)+fk(a,b,i3,j3);
}

vector<ll>ord[6];
ll what[8];

void go(ll p)
{
        if(p==8)
        {
                bool ok=1;
                ll mi;
                ll ma;
                for(ll i=0;i<8 && ok;i++)
                {
                        ll dmin=(1LL<<60),cnt=0;
                        ll dmax=-dmin,cntma=0;
                        for(ll j=0;j<8;j++)
                        {
                                if(i==j)
                                        continue;
                                ll cur=calc(i,j,ord[what[i]][0],ord[what[i]][1],ord[what[i]][2],ord[what[j]][0],ord[what[j]][1],ord[what[j]][2]);
                                if(cur<dmin)
                                {
                                        dmin=cur;
                                        cnt=0;
                                }
                                cnt+=(dmin==cur);
                                if(cur==0)
                                {
                                        ok=0;
                                        break;
                                }
                                if(cur>dmax)
                                {
                                        dmax=cur;
                                        cntma=0;
                                }
                                cntma+=(dmax==cur);
                        }
                        if(i==0)
                                mi=dmin;
                        if(i==0)
                                ma=dmax;
                        if(mi!=dmin)
                        {
                                ok=0;
                                break;
                        }
                        if(ma!=dmax)
                        {
                                ok=0;
                                break;
                        }
                        if(cnt!=3)
                        {
                                ok=0;
                                break;
                        }
                        if(cntma!=1)
                        {
                                ok=0;
                                break;
                        }
                }
                if(ma!=3*mi)
                        ok=0;
                /// mx=3*mi

                if(ok)
                {
                        cout<<"YES\n";
                        for(ll i=0;i<8;i++)
                        {
                                for(ll j=0;j<3;j++)
                                        cout<<mt[i][ord[what[i]][j]]<<" ";
                                cout<<"\n";
                        }
                        exit(0);
                }
                return;
        }
        for(ll i=0;i<6;i++)
        {
                what[p]=i;
                go(p+1);
        }
}

int main()
{
        for(ll i=0;i<8;i++)
                for(ll j=0;j<3;j++)
                        cin>>mt[i][j];
        ord[0]={0,1,2};
        ord[1]={0,2,1};
        ord[2]={1,0,2};
        ord[3]={1,2,0};
        ord[4]={2,0,1};
        ord[5]={2,1,0};
        go(0);
        cout<<"NO\n";
        return 0;
}