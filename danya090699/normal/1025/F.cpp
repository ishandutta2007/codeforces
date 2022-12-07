#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e3+10;
vector <pair <int, int> > pairs;
int p[sz], p2[sz], pt[sz][2];
pair <int, int> f(pair <int, int> i)
{
    int vx=pt[i.first][0]-pt[i.second][0];
    int vy=pt[i.first][1]-pt[i.second][1];
    if(vy<0)
    {
        vy=-vy, vx=-vx;
    }
    if(vy==0 and vx>0) vx=-vx;
    return make_pair(vx, vy);
}
int s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2-x1)*(y2+y1)+(x3-x2)*(y3+y2)+(x1-x3)*(y1+y3);
}
bool comp(pair <int, int> a, pair <int, int> b)
{
    pair <int, int> ve1=f(a), ve2=f(b);
    return (s(0, 0, ve1.first, ve1.second, ve2.first, ve2.second)>0);
}
bool comp2(int a, int b)
{
    if(pt[a][1]!=pt[b][1]) return pt[a][1]<pt[b][1];
    else return pt[a][0]>pt[b][0];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        p[a]=a;
        cin>>pt[a][0]>>pt[a][1];
        for(int b=0; b<a; b++) pairs.push_back(make_pair(a, b));
    }
    sort(pairs.begin(), pairs.end(), comp);
    sort(p, p+n, comp2);
    for(int a=0; a<n; a++) p2[p[a]]=a;
    long long an=0;
    for(int a=0; a<pairs.size(); a++)
    {
        int nu1=pairs[a].first, nu2=pairs[a].second;
        int pos1=p2[nu1], pos2=p2[nu2];
        if(pos1>pos2) swap(pos1, pos2);
        int q1=pos1, q2=n-(pos2+1);
        if(q1>1 and q2>1)
        {
            an+=1ll*((q1*(q1-1))/2)*((q2*(q2-1))/2);
        }
        swap(p[pos1], p[pos2]);
        swap(p2[nu1], p2[nu2]);
    }
    cout<<an;
}