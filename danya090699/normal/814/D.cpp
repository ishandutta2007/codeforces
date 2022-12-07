#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
struct ro
{
    int x, y, r;
};
ro *ar;
int *pr;
bool comp(ro a, ro b){return a.r<b.r;}
vector <int> *sv;
double an=0, PI=3.14159265359;
void dfs(int v, int va)
{
    an+=PI*ar[v].r*ar[v].r*va;
    if(va==1) va=-1;
    else va=1;
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a], va);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    ar=new ro[n], pr=new int[n], sv=new vector <int> [n];
    for(int a=0; a<n; a++) pr[a]=-1;
    for(int a=0; a<n; a++) cin>>ar[a].x>>ar[a].y>>ar[a].r;
    sort(ar, ar+n, comp);
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            if(ar[a].r<ar[b].r)
            {
                int di=(ar[a].x-ar[b].x)*(ar[a].x-ar[b].x)+(ar[a].y-ar[b].y)*(ar[a].y-ar[b].y);
                if(di<=(ar[b].r*ar[b].r))
                {
                    pr[a]=b;
                    sv[b].push_back(a);
                    break;
                }
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        if(pr[a]==-1)
        {
            an+=PI*ar[a].r*ar[a].r;
            for(int b=0; b<sv[a].size(); b++) dfs(sv[a][b], 1);
        }
    }
    cout<<fixed<<setprecision(11)<<an;
    //cout<<fixed<<setprecision(11)<<M_PI;
}