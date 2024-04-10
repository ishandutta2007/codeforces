#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=50+7;

int n;
int v[N];
int prefix[N];

int get(int l,int r)
{
        return prefix[r]-prefix[l-1];
}

map<int,vector<pair<int,int>>>interv;

bool cmp(pair<int,int>a,pair<int,int>b)
{
        if(a.second==b.second)
        {
                return a.first<b.first;
        }
        else
        {
                return a.second<b.second;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                prefix[i]=prefix[i-1]+v[i];
        }
        for(int l=1;l<=n;l++)
        {
                for(int r=l;r<=n;r++)
                {
                        interv[get(l,r)].push_back({l,r});
                }
        }
        int bestk=0;
        vector<pair<int,int>>sol;
        for(auto &it:interv)
        {
                vector<pair<int,int>>ve;
                ve=it.second;
                if(ve.size()==0)
                {
                        continue;
                }
                sort(ve.begin(),ve.end(),cmp);
                int k;
                vector<pair<int,int>>res;
                int lastr=ve[0].second;
                res.push_back({ve[0].first,ve[0].second});
                for(int j=1;j<ve.size();j++)
                {
                        int st=ve[j].first;
                        int dr=ve[j].second;
                        if(lastr<st)
                        {
                                lastr=dr;
                                res.push_back({st,dr});
                        }
                }
                k=res.size();
                if(k>bestk)
                {
                        bestk=k;
                        sol=res;
                }
        }
        cout<<bestk<<"\n";
        for(auto &it:sol)
        {
                cout<<it.first<<" "<<it.second<<"\n";
        }
        return 0;
}
/**
**/