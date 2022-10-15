#include <bits/stdc++.h>

using namespace std;

int res=0;
vector<int>sol;

void upd(int cur,vector<int>a)
{
        if(cur>res)
        {
                res=cur;
                sol=a;
        }
}

void print()
{
        cout<<res<<"\n";
        cout<<sol.size()<<"\n";
        sort(sol.begin(),sol.end());
        for(auto &it:sol)
        {
                cout<<it<<" ";
        }
        cout<<"\n";
}

const int N=(int)1e5+7;
const int M=300+7;

int n,m;
int value[N];
int v[N];
int l[M];
int r[M];

vector<int>f[N];
vector<int>s[N];

void cop()
{
        for(int i=1;i<=n;i++)
        {
                v[i]=value[i];
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>value[i];
        for(int i=1;i<=m;i++)
        {
                cin>>l[i]>>r[i];
                f[l[i]].push_back(i);
                s[r[i]].push_back(i);
        }
        v[0]=v[n+1]=(1<<30);
        int mi;
        cop();
        mi=(1<<30);
        for(int i=1;i<=n;i++)
        {
                mi=min(mi,v[i-1]);
                for(auto &it:s[i-1])
                {
                        for(int poz=l[it];poz<=r[it];poz++)
                        {
                                v[poz]--;
                                mi=min(mi,v[poz]);
                        }
                }
                vector<int>a;
                for(int j=1;j<=m;j++)
                {
                        if(l[j]<=i && i<=r[j]) continue;
                        a.push_back(j);
                }
                upd(v[i]-mi,a);
        }
        cop();
        mi=(1<<30);
        for(int i=n;i>=1;i--)
        {
                mi=min(mi,v[i+1]);
                for(auto &it:f[i+1])
                {
                        for(int poz=l[it];poz<=r[it];poz++)
                        {
                                v[poz]--;
                                mi=min(mi,v[poz]);
                        }
                }
                vector<int>a;
                for(int j=1;j<=m;j++)
                {
                        if(l[j]<=i && i<=r[j]) continue;
                        a.push_back(j);
                }
                upd(v[i]-mi,a);
        }
        print();
        return 0;
}