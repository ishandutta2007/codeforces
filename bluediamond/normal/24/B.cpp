#include<bits/stdc++.h>

using namespace std;

int score[]={0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct info
{
    int total;
    vector<int>poz;
};

map<string,info>mp;

string auxx[55];

int t;

struct info2
{
    string a;
    int total;
    int ap[55];
};

bool cmp1(info2 a,info2 b)
{
    if(a.total!=b.total)
        return a.total<b.total;
    for(int i=1;i<=50;i++)
        if(a.ap[i]!=b.ap[i])
            return a.ap[i]<b.ap[i];
}

bool cmp2(info2 a,info2 b)
{
    if(a.ap[1]!=b.ap[1])
        return a.ap[1]<b.ap[1];
    if(a.total!=b.total)
        return a.total<b.total;
    for(int i=2;i<=50;i++)
        if(a.ap[i]!=b.ap[i])
            return a.ap[i]<b.ap[i];
}

info2 v[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>auxx[i];
            mp[auxx[i]].poz.push_back(i);
        }
        for(int i=1;i<=min(n,10);i++)
        {
            mp[auxx[i]].total+=score[i];
        }
    }
    int cnt=0;
    for(auto itr:mp)
    {
        cnt++;
        v[cnt].a=itr.first;
        v[cnt].total=itr.second.total;
        for(int j=0;j<itr.second.poz.size();j++)
        {
            v[cnt].ap[itr.second.poz[j]]++;
        }
    }
    sort(v+1,v+cnt+1,cmp1);
    cout<<v[cnt].a<<"\n";
    sort(v+1,v+cnt+1,cmp2);
    cout<<v[cnt].a<<"\n";
    return 0;
}