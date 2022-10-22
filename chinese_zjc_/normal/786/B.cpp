//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,a,b,c,d,e,A,B;
struct edge{
    int v,t;
};
struct node{
    int dis,lson,rson,l,r;
    bool belong,went;
    vector <edge> e;
};
vector <node> h;
void build1(int now)
{
    // cout<<now<<' '<<h[now].l<<' '<<h[now].r<<endl;
    if(h[now].l==h[now].r)
    {
        return;
    }
    int mid=(h[now].l+h[now].r)>>1;
    if(h[now].l==mid)
    {
        h[now].lson=h[now].l-1;
    }
    else
    {
        h.push_back((node){INF,-1,-1,h[now].l,mid,false,false});
        h[now].lson=h.size()-1;
        build1(h[now].lson);
    }
    h[now].e.push_back((edge){0,h[now].lson});
    if(h[now].r==mid+1)
    {
        h[now].rson=h[now].r-1;
    }
    else
    {
        h.push_back((node){INF,-1,-1,mid+1,h[now].r,false,false});
        h[now].rson=h.size()-1;
        build1(h[now].rson);
    }
    h[now].e.push_back((edge){0,h[now].rson});
}
void build2(int now)
{
    if(now==-1||h[now].l==h[now].r)
    {
        return;
    }
    int mid=(h[now].l+h[now].r)>>1;
    if(h[now].l==mid)
    {
        h[now].lson=h[now].l-1;
    }
    else
    {
        h.push_back((node){INF,-1,-1,h[now].l,mid,true,false});
        h[now].lson=h.size()-1;
        build2(h[now].lson);
    }
    h[h[now].lson].e.push_back((edge){0,now});
    if(h[now].r==mid+1)
    {
        h[now].rson=h[now].r-1;
    }
    else
    {
        h.push_back((node){INF,-1,-1,mid+1,h[now].r,true,false});
        h[now].rson=h.size()-1;
        build2(h[now].rson);
    }
    h[h[now].rson].e.push_back((edge){0,now});
}
void add1(int now)
{
    // cout<<h[now].l<<' '<<h[now].r<<endl;
    if(now==-1||d<h[now].l||h[now].r<c)
    {
        return;
    }
    if(c<=h[now].l&&h[now].r<=d)
    {
        h[b-1].e.push_back((edge){e,now});
        return;
    }
    add1(h[now].lson);
    add1(h[now].rson);
}
void add2(int now)
{
    if(now==-1||d<h[now].l||h[now].r<c)
    {
        return;
    }
    if(c<=h[now].l&&h[now].r<=d)
    {
        h[now].e.push_back((edge){e,b-1});
        return;
    }
    add2(h[now].lson);
    add2(h[now].rson);
}
queue<int>dl;
void spfa()
{
    h[s-1].dis=0;
    dl.push(s-1);
    h[s-1].went=true;
    while(!dl.empty())
    {
        int now=dl.front();
        dl.pop();
        h[now].went=false;
        for(int i=0;i<(int)h[now].e.size();++i)
        {
            if(h[h[now].e[i].t].dis>h[now].dis+h[now].e[i].v)
            {
                h[h[now].e[i].t].dis=h[now].dis+h[now].e[i].v;
                if(!h[h[now].e[i].t].went)
                {
                    h[h[now].e[i].t].went=true;
                    dl.push(h[now].e[i].t);
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)
    {
        h.push_back((node){INF,-1,-1,i,i,false,false});
    }
    h.push_back((node){INF,-1,-1,1,n,false,false});
    A=h.size()-1;
    h.push_back((node){INF,-1,-1,1,n,true,false});
    B=h.size()-1;
    build1(A);
    build2(B);
    for(int i=1;i<=m;++i)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c>>d;
            h[b-1].e.push_back((edge){d,c-1});
        }
        if(a==2)
        {
            cin>>b>>c>>d>>e;
            add1(A);
        }
        if(a==3)
        {
            cin>>b>>c>>d>>e;
            add2(B);
        }
    }
    // for(int i=0;i<(int)h.size();++i)
    // {
    //     for(int j=0;j<(int)h[i].e.size();++j)
    //     {
    //         cout<<i<<' '<<h[i].e[j].t<<' '<<h[i].e[j].v<<endl;
    //     }
    // }
    // cout<<endl;
    spfa();
    for(int i=0;i<n;++i)
    {
        cout<<(h[i].dis==INF?-1:h[i].dis)<<' ';
    }
    return 0;
}