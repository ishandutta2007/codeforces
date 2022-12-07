#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, L;
    cin>>n>>k>>L;
    map <int, int> sex, sey;
    vector <int> cx, cy;
    int ar[n][3];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a][0]>>ar[a][1]>>ar[a][2];
        ar[a][2]--;
        sex[ar[a][0]]=0, sey[ar[a][1]]=0;
    }
    for(auto it=sex.begin(); it!=sex.end(); it++)
    {
        (*it).second=cx.size();
        cx.push_back((*it).first);
    }
    for(auto it=sey.begin(); it!=sey.end(); it++)
    {
        (*it).second=cy.size();
        cy.push_back((*it).first);
    }
    vector <pair <int, int> > sp[cx.size()];
    for(int a=0; a<n; a++)
    {
        sp[sex[ar[a][0]]].push_back({ar[a][1], ar[a][2]});
    }
    for(int a=0; a<cx.size(); a++)
    {
        if(a)
        {
            for(int b=0; b<sp[a].size(); b++)
            {
                sp[a-1].push_back({L, sp[a][b].second});
            }
        }
    }
    for(int a=0; a<k; a++) sp[cx.size()-1].push_back({L, a});

    for(int a=0; a<cx.size(); a++) sort(sp[a].begin(), sp[a].end());

    int an=0;

    for(int a=0; a<cy.size(); a++)
    {
        vector <pair <int, int> > st[k], add[cx.size()];
        for(int b=0; b<k; b++) st[b].push_back({0, L});
        for(int b=cx.size()-1; b>=0; b--)
        {
            for(int c=0; c<sp[b].size(); c++)
            {
                int y=sp[b][c].first, i=sp[b][c].second;
                if(y>=cy[a] and st[i].back().second!=cx[b])
                {
                    while(st[i].back().first>y)
                    {
                        int y2=st[i].back().first;
                        st[i].pop_back();
                        int x2=st[i].back().second;
                        add[b+1].push_back({y2, x2});
                    }
                    st[i].push_back({y, cx[b]});
                }
            }
        }
        for(int b=0; b<k; b++)
        {
            while(st[b].size()>1)
            {
                int y2=st[b].back().first;
                st[b].pop_back();
                int x2=st[b].back().second;
                add[0].push_back({y2, x2});
            }
        }
        map <int, pair <int, int>, greater <int> > ma;
        ma[0]={L+1, L+2};
        long long su=0;
        for(int b=0; b<cx.size(); b++)
        {
            add[b].push_back({L, cx[b]});
            while(add[b].size())
            {
                int y=add[b].back().first, x=add[b].back().second, q=0;
                add[b].pop_back();

                auto it=ma.lower_bound(y), start=it;
                while(1)
                {
                    int y2=(*it).first, x2=(*it).second.first, q2=(*it).second.second;
                    if(x>=x2)
                    {
                        su+=1ll*q2*(y-y2);
                        q+=q2;
                        it++;
                    }
                    else
                    {
                        if(y>y2)
                        {
                            int d=max(0, q2-(x2-x));
                            su+=1ll*d*(y-y2);
                            q+=d;
                            (*it).second.second-=d;
                        }
                        break;
                    }
                }
                ma.erase(start, it);
                if(q) ma[y]={x, q};
            }


            int d=(1ll*L*(L+1)-su)%mod;

            d=1ll*d*(b ? cx[b]-cx[b-1] : cx[b]+1)%mod;

            d=1ll*d*(a ? cy[a]-cy[a-1] : cy[a]+1)%mod;

            an=(an+d)%mod;
        }
    }
    cout<<an;
}