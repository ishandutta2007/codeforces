#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> a(n);
    map<int,int> hhor;
    map<int,int> hver;
    set<array<int,2>> hor[n];
    set<array<int,2>> ver[n];
    int idhor=0,idver=0;
    for(int i=0;i<n;i++)
    {
        auto &[x,y]=a[i];
        cin >> x >> y;
        if(hhor.find(y)==hhor.end()) hhor[y]=idhor++;
        if(hver.find(x)==hver.end()) hver[x]=idver++;
        hor[hhor[y]].insert({x,i});
        ver[hver[x]].insert({y,i});
    }
    auto one=[&](int x,int y)->array<int,2>
    {
        array<int,2> tmp={-1,-1};
        int idx=0;
        if(hhor.find(y)==hhor.end()) return tmp;
        int id=hhor[y];
        auto it=hor[id].lower_bound({x,-1});
        if(it!=hor[id].end()) tmp[idx++]=((*it)[1]);
        if(it!=hor[id].begin())
        {
            it--;
            tmp[idx++]=((*it)[1]);
        }
        return tmp;
    };
    auto two=[&](int x,int y)->array<int,2>
    {
        array<int,2> tmp={-1,-1};
        int idx=0;
        if(hver.find(x)==hver.end()) return tmp;
        int id=hver[x];
        auto it=ver[id].lower_bound({y,-1});
        if(it!=ver[id].end()) tmp[idx++]=((*it)[1]);
        if(it!=ver[id].begin())
        {
            it--;
            tmp[idx++]=((*it)[1]);
        }
        return tmp;
    };
    vector<vector<vector<array<int,4>>>> pre(n,vector<vector<array<int,4>>>(n,vector<array<int,4>>(2)));
    auto ini=[&](int x,int y,int i,int j,int e)
    {
        array<int,4> &now=pre[i][j][e];
        array<int,2> tmp=one(x,y);
        now[0]=tmp[0];
        now[1]=tmp[1];
        tmp=two(x,y);
        now[2]=tmp[0];
        now[3]=tmp[1];
    };
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            auto [x1,y1]=a[i];
            auto [x2,y2]=a[j];
            if(x1==x2) ini(x1,(y1+y2)/2,i,j,0);
            else if(y1==y2) ini((x1+x2)/2,y1,i,j,0);
            else
            {
                ini(x1,y2,i,j,0);
                ini(x2,y1,i,j,1);
            }
        }
    }
    const ll lim=(1ll<<31);
    ll l=0,r=lim;
    while(l<r-1)
    {
        int m=(l+r)/2;
        vector<int> v[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                auto [x1,y1]=a[i];
                auto [x2,y2]=a[j];
                if((x1==x2&&abs(y1-y2)<=m)||(y1==y2&&abs(x1-x2)<=m))
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<int> c(n,-1);
        int now=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]!=-1) continue;
            c[i]=now;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int e=q.front();
                q.pop();
                for(int to:v[e])
                {
                    if(c[to]!=-1) continue;
                    c[to]=now;
                    q.push(to);
                }
            }
            now++;
        }
        bool ok=(now==1);
        if(now<=4)
        {
            auto go=[&](int x,int y,int i,int j,int e)
            {
                vector<int> z(now,0);
                for(int b:pre[i][j][e]) if(b!=-1&&abs(x-a[b][0])+abs(y-a[b][1])<=m) z[c[b]]=1;
                bool b=1;
                for(int k=0;k<now;k++) b&=z[k];
                if(b) ok=1;
            };
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    auto [x1,y1]=a[i];
                    auto [x2,y2]=a[j];
                    if(x1==x2) go(x1,(y1+y2)/2,i,j,0);
                    else if(y1==y2) go((x1+x2)/2,y1,i,j,0);
                    else
                    {
                        go(x1,y2,i,j,0);
                        go(x2,y1,i,j,1);
                    }
                }
            }
        }
        if(ok) r=m;
        else l=m;
    }
    if(r<lim) cout << r << "\n";
    else cout << "-1\n";
    return 0;
}