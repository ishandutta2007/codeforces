#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> x_events; //x,id
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> y_events; //y,id
    priority_queue<int,vector<int>,greater<int>> v_rays; //x
    priority_queue<int,vector<int>,greater<int>> h_rays; //y
    vector<array<int,2>> rays(n+1,{0,0});
    set<array<int,2>> losing;
    for(int i=0;i<=n;i++)
    {
        int x=0,y=0;
        if(i>0) cin >> x >> y;
        rays[i]={x,y};
        x_events.push({x,i});
        y_events.push({y,i});
        losing.insert(rays[i]);
    }
    map<array<int,2>,int> bad; //x1,x2,y1
    int x=0,y=0;
    auto add=[&]()
    {
        while(!x_events.empty()&&x_events.top()[0]==x)
        {
            int id=x_events.top()[1];
            x_events.pop();
            h_rays.push(rays[id][1]);
        }
        while(!y_events.empty()&&y_events.top()[0]==y)
        {
            int id=y_events.top()[1];
            y_events.pop();
            v_rays.push(rays[id][0]);
        }
    };
    auto fix=[&]()
    {
        while(!v_rays.empty()&&v_rays.top()<x) v_rays.pop();
        while(!h_rays.empty()&&h_rays.top()<y) h_rays.pop();
    };
    auto go=[&](){add();fix();};
    const int lim=1000000000;
    while(1)
    {
        while(1)
        {
            bool mv=0;
            go();
            if(!v_rays.empty()&&v_rays.top()==x) {x++;mv=1;}
            go();
            if(!h_rays.empty()&&h_rays.top()==y) {y++;mv=1;}
            go();
            if(mv==0) break;
        }
        int xs=x;
        int ys=y;
        if(x_events.empty()&&y_events.empty()&&v_rays.empty()&&h_rays.empty())
        {
            bad[{xs,lim}]=ys;
            break;
        }
        int xn=lim+1;
        if(!x_events.empty()) xn=x_events.top()[0];
        if(!v_rays.empty()) xn=min(xn,v_rays.top());
        int yn=lim+1;
        if(!y_events.empty()) yn=y_events.top()[0];
        if(!h_rays.empty()) yn=min(yn,h_rays.top());
        if(xn-xs<=yn-ys)
        {
            bad[{xs,xn-1}]=ys;
            tie(x,y)=make_pair(xn,ys+(xn-xs));
        }
        else
        {
            bad[{xs,xs+(yn-ys)-1}]=ys;
            tie(x,y)=make_pair(xs+(yn-ys),yn);
        }
    }
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        bool res=1;
        if(losing.find({a,b})!=losing.end()) res=0;
        auto it=bad.lower_bound({a+1,0});
        if(it!=bad.begin())
        {
            it--;
            auto [x1,x2]=(it->first);
            int y1=(it->second);
            if(x1<=a&&a<=x2&&a-x1==b-y1) res=0;
        }
        if(res) cout << "WIN\n";
        else cout << "LOSE\n";
    }
    return 0;
}