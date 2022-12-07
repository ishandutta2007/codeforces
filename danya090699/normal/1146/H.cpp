#include <bits/stdc++.h>
using namespace std;
const int sz=3e2+10;
long long s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 1ll*(x2-x1)*(y2+y1)+1ll*(x3-x2)*(y3+y2)+1ll*(x1-x3)*(y1+y3);
}
long long dp[sz][sz][6];
int ar[sz][2];
int f(int x, int y)
{
    if(x>0 or x==0 and y>0) return 0;
    else return 1;
}
bool comp(pair <int, int> v1, pair <int, int> v2)
{
    int vx1=ar[v1.second][0]-ar[v1.first][0], vy1=ar[v1.second][1]-ar[v1.first][1];
    int vx2=ar[v2.second][0]-ar[v2.first][0], vy2=ar[v2.second][1]-ar[v2.first][1];

    int ty1=f(vx1, vy1), ty2=f(vx2, vy2);
    if(ty1!=ty2) return ty1<ty2;
    else return (s(0, 0, vx1, vy1, vx2, vy2)>0);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) if(a!=b) sp.push_back({a, b});
    }
    sort(sp.begin(), sp.end(), comp);
    for(int a=0; a<n; a++) dp[a][a][0]=1;
    for(int a=0; a<sp.size(); a++)
    {
        int f=sp[a].first, t=sp[a].second;
        for(int b=0; b<n; b++) for(int c=0; c<5; c++) dp[b][t][c+1]+=dp[b][f][c];
    }
    long long an=0;
    for(int a=0; a<n; a++) an+=dp[a][a][5];
    cout<<an;
}