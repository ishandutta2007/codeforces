#include <bits/stdc++.h>

using namespace std;

int h(string a)
{
    a[0]-='A';
    a[1]-='A';
    a[2]-='A';
    return a[0]*26*26+a[1]*26+a[2];
}

string afis(int val)
{
    string ans="";
    ans+=char('A'+val/26/26);
    ans+=char('A'+val/26%26);
    ans+=char('A'+val%26);
    return ans;
}

const int N=1000+5;
const int L=17575+5;
int n;
int a[N],b[N];
int cnt[L]; vector<int>who[L];
int force[N];
bool viz[N];

void nitro(int ind)
{
    viz[ind]=1;
    for(int i=1;i<=n;i++)
    {
        if(viz[i] || force[i]!=-1)
            continue;
        if(a[i]==b[ind])
        {
            force[i]=b[i];
            nitro(i);
        }
    }
}

vector<string>answer;
int tipe[N];

bool check()
{
    vector<string>auxx;
    auxx=answer;
    sort(auxx.begin(),auxx.end());
    for(int i=0;i+1<n;i++)
    {
        if(auxx[i]==auxx[i+1])
            return 0;
    }
    for(int i=0;i<n;i++)
        if(h(answer[i])==b[i+1])
            tipe[i+1]=2;
        else
            tipe[i+1]=1;
    for(int i=1;i<=n;i++)
    {
        if(tipe[i]==2)
        {
            for(int j=1;j<=n;j++)
                if(tipe[j]==1)
                {
                    if(a[i]==a[j])
                        return 0;
                }
        }
    }
    return 1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string x,y;
        cin>>x>>y;
        string aux; aux+=x[0]; aux+=x[1]; aux+=x[2];
        a[i]=h(aux);
        string ux; ux+=x[0]; ux+=x[1]; ux+=y[0];
        b[i]=h(ux);
        cnt[a[i]]++; who[a[i]].push_back(i);
        force[i]=-1;
    }
    bool t1=1;
    for(int i=1;i<=n;i++)
        if(cnt[a[i]]>1)
        {
            t1=0;
            break;
        }
    if(t1)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            cout<<afis(a[i])<<"\n";
        }
        return 0;
    }
    for(int i=0;i<L;i++)
    {
        int sz=who[i].size();
        if(sz<=1)
            continue;
        for(auto itr:who[i])
        {
            viz[itr]=1;
            force[itr]=b[itr];
        }
    }
    for(int i=0;i<L;i++)
    {
        int sz=who[i].size();
        if(sz<=1)
            continue;
        for(auto itr:who[i])
            nitro(itr);
    }
    for(int i=1;i<=n;i++)
    {
        if(force[i]==-1)
        {
            answer.push_back(afis(a[i]));
        }
        else
        {
            answer.push_back(afis(force[i]));
        }
    }
    if(check())
    {
        cout<<"YES\n";
        for(auto itr:answer)
        {
            cout<<itr<<"\n";
        }
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
/**
**/