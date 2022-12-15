#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;
vector<vector<int> > ms;//x+y
vector<vector<int> > ss;//x-y+m
vector<int> x,y;
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int x0,y0,k;
    cin>>x0>>y0>>k;
    ms.resize(2*max(x0,y0));
    ss.resize(2*max(x0,y0));
    x.resize(k);
    y.resize(k);
    ans.resize(k);
    for(int i=0;i<k;i++)
    {
        cin>>x[i]>>y[i];
        ms[x[i]+y[i]].push_back(i);
        ss[x[i]-y[i]+y0].push_back(i);
        ans[i]=-1;
    }
    ll t=0,lx=0,ly=0,dir=1;
    while(true)
    {
        if(dir==1)
        {
            int tmp=lx-ly+y0;
            for(int i=0;i<ss[tmp].size();i++)
            {
                int n=ss[tmp][i];
                if(ans[n]==-1)ans[n]=abs(x[n]-lx)+t;
            }
            int dt=min(x0-lx,y0-ly);
            dir=(dt==x0-lx?2:4);
            lx+=dt;
            ly+=dt;
            t+=dt;
            if(ly==y0&&lx==x0)break;
        }
        else if(dir==2)
        {
            int tmp=lx+ly;
            for(int i=0;i<ms[tmp].size();i++)
            {
                int n=ms[tmp][i];
                if(ans[n]==-1)ans[n]=abs(x[n]-lx)+t;
            }
            int dt=min(lx,y0-ly);
            dir=(dt==lx?1:3);
            lx-=dt;
            ly+=dt;
            t+=dt;
            if(ly==y0&&lx==0)break;
        }
        else if(dir==3)
        {
            int tmp=lx-ly+y0;
            for(int i=0;i<ss[tmp].size();i++)
            {
                int n=ss[tmp][i];
                if(ans[n]==-1)ans[n]=abs(x[n]-lx)+t;
            }
            int dt=min(lx,ly);
            dir=(dt==lx?4:2);
            lx-=dt;
            ly-=dt;
            t+=dt;
            if(ly==0&&lx==0)break;
        }
        else if(dir==4)
        {
            int tmp=lx+ly;
            for(int i=0;i<ms[tmp].size();i++)
            {
                int n=ms[tmp][i];
                if(ans[n]==-1)ans[n]=abs(x[n]-lx)+t;
            }
            int dt=min(x0-lx,ly);
            dir=(dt==x0-lx?3:1);
            lx+=dt;
            ly-=dt;
            t+=dt;
            if(ly==0&&lx==x0)break;
        }
        //cout<<lx<<" "<<ly<<" "<<dir<<" "<<t<<endl;
    }
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<endl;
    }
}