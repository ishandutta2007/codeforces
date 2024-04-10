#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
const int maxn=1e5+7;
int vis[maxn];
void init()
{
    int cnt=0;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
     //       if(i<350) cnt++;
        }
        for(int j=i*2;j<maxn;j+=i) vis[j]=1;
    }
}
int del(int u)
{
    cout<<"B "<<u<<endl;
    int ret;
    cin>>ret;
    return ret;
}
int ask(int u)
{
    cout<<"A "<<u<<endl;
    int ret;
    cin>>ret;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    int sqr=sqrt(n);
    long long ans=1;
    vector<int> ap;
    vector<int> bp;
    for(auto p:prime)
    {
        if(p>n) break;
        if(p<=sqr)
        {
            del(p);
            if(ask(p))
            {
                ans*=p;
                ap.push_back(p);
            }
        }
        else{
            bp.push_back(p);
        }
    }
    int cur=ask(1);
    for(int i=0;i<bp.size();i+=100)
    {
        bool suc=0;
        for(int j=i;j<min(i+100,(int)bp.size());j++)
        {
            int cc=del(bp[j]);
            if(cc!=1)
            {
                ans*=bp[j];
                ap.push_back(bp[j]);
                suc=1;
                break;
            }
            cur--;
        }
        if(suc) break;
        int tar=ask(1);
        if(tar!=cur)
        {
            for(int j=i;j<min(i+100,(int)bp.size());j++)
            {
                if(ask(bp[j]))
                {
                    ans*=bp[j];
                    ap.push_back(bp[j]);
                    break;
                }
            }
            break;
        }
    }
    for(auto u:ap)
    {
        while(ans*u<=n&&ask(ans*u))
            ans*=u;
    }
    cout<<"C "<<ans<<endl;
}