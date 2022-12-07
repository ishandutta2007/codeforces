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
    int n, S, an1=-1, an2=-1, an3=-1;
    cin>>n>>S;
    S*=2;
    for(int a=0; a<n; a++)
    {
        p[a]=a;
        cin>>pt[a][0]>>pt[a][1];
        for(int b=0; b<a; b++) pairs.push_back(make_pair(a, b));
    }
    sort(pairs.begin(), pairs.end(), comp);
    sort(p, p+n, comp2);
    for(int a=0; a<n; a++) p2[p[a]]=a;
    for(int a=0; a<pairs.size(); a++)
    {
        int nu1=pairs[a].first, nu2=pairs[a].second;
        int lg=-1, rg=p2[nu1], fo=-1;
        while(rg-lg>1)
        {
            int mid=(lg+rg)>>1;
            int nu3=p[mid];
            int cus=s(pt[nu1][0], pt[nu1][1], pt[nu2][0], pt[nu2][1], pt[nu3][0], pt[nu3][1]);
            if(abs(cus)==S) fo=nu3;
            if(abs(cus)>S) lg=mid;
            else rg=mid;
        }
        lg=p2[nu1], rg=n;
        while(rg-lg>1)
        {
            int mid=(lg+rg)>>1;
            int nu3=p[mid];
            int cus=s(pt[nu1][0], pt[nu1][1], pt[nu2][0], pt[nu2][1], pt[nu3][0], pt[nu3][1]);
            if(abs(cus)==S) fo=nu3;
            if(abs(cus)<S) lg=mid;
            else rg=mid;
        }
        if(fo!=-1)
        {
            an1=nu1, an2=nu2, an3=fo;
            break;
        }
        int pos1=p2[nu1], pos2=p2[nu2];
        swap(p[pos1], p[pos2]);
        swap(p2[nu1], p2[nu2]);
    }
    if(an1!=-1)
    {
        cout<<"Yes\n";
        cout<<pt[an1][0]<<" "<<pt[an1][1]<<"\n";
        cout<<pt[an2][0]<<" "<<pt[an2][1]<<"\n";
        cout<<pt[an3][0]<<" "<<pt[an3][1]<<"\n";
    }
    else cout<<"No";
}