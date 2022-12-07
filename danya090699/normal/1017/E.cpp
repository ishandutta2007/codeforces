#include <bits/stdc++.h>
#define int long long
using namespace std;
int s(pair <int, int> p1, pair <int, int> p2, pair <int, int> p3)
{
    int x1=p1.first, y1=p1.second;
    int x2=p2.first, y2=p2.second;
    int x3=p3.first, y3=p3.second;
    return (x2-x1)*(y2+y1)+(x3-x2)*(y3+y2)+(x1-x3)*(y1+y3);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n[2];
    cin>>n[0]>>n[1];
    vector <pair <int, int> > hull[2];
    for(int i=0; i<2; i++)
    {
        vector <pair <int, int> > po(n[i]);
        for(int a=0; a<n[i]; a++)
        {
            scanf("%lld%lld", &po[a].first, &po[a].second);
        }
        sort(po.begin(), po.end());
        for(int a=0; a<po.size(); a++)
        {
            hull[i].push_back(po[a]);
            while(hull[i].size()>2)
            {
                int m=hull[i].size();
                if(s(hull[i][m-3], hull[i][m-2], hull[i][m-1])<=0) hull[i].erase(hull[i].begin()+(m-2));
                else break;
            }
        }
        vector <pair <int, int> > dow;
        reverse(po.begin(), po.end());
        for(int a=0; a<po.size(); a++)
        {
            dow.push_back(po[a]);
            while(dow.size()>2)
            {
                int m=dow.size();
                if(s(dow[m-3], dow[m-2], dow[m-1])<=0) dow.erase(dow.begin()+(m-2));
                else break;
            }
        }
        for(int a=1; a+1<dow.size(); a++) hull[i].push_back(dow[a]);
    }
    if(hull[0].size()==hull[1].size())
    {
        vector <pair <int, int> > ve[2], s;
        for(int i=0; i<2; i++)
        {
            int m=hull[i].size();
            for(int a=0; a<m; a++)
            {
                pair <int, int> p1=hull[i][a], p2=hull[i][(a+1)%m], p3=hull[i][(a+2)%m];
                int vx1=p1.first-p2.first, vy1=p1.second-p2.second;
                int vx2=p1.first-p3.first, vy2=p1.second-p3.second;
                ve[i].push_back(make_pair(vx1*vx1+vy1*vy1, vx2*vx2+vy2*vy2));
            }
        }

        for(int a=0; a<ve[0].size(); a++) s.push_back(ve[0][a]);
        s.push_back(make_pair(-1, -1));
        for(int i=0; i<2; i++) for(int a=0; a<ve[1].size(); a++) s.push_back(ve[1][a]);

        int m=s.size(), ok=0;
        int zf[m], l=0, r=-1;
        zf[0]=0;
        for(int a=1; a<m; a++)
        {
            zf[a]=0;
            if(a<=r) zf[a]=min(zf[a-l], r-a+1);
            while(a+zf[a]<m)
            {
                if(s[zf[a]]==s[a+zf[a]]) zf[a]++;
                else break;
            }
            if(zf[a]==hull[0].size()) ok=1;
            if(a+zf[a]-1>r)
            {
                l=a, r=a+zf[a]-1;
            }
        }
        if(ok) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
}