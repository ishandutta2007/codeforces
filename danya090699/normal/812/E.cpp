#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
int n, xo[2], q[2], *ar, odd, ev;
map <int, int> ma[2];
vector <int> *sv;
void dfs(int v, int h)
{
    q[h]++;
    xo[h]=(xo[h]^ar[v]);
    ma[h][ar[v]]++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne, (h+1)%2);
    }
    if(sv[v].size()==0)
    {
        odd=h, ev=(h+1)%2;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    ar=new int[n], sv=new vector <int>[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=1; a<n; a++)
    {
        int v;
        cin>>v;
        v--;
        sv[v].push_back(a);
    }
    xo[0]=0, xo[1]=0, q[0]=0, q[1]=0;
    dfs(0, 0);
    long long an=0;
    if(xo[odd]==0)
    {
        an+=1ll*q[0]*(q[0]-1)/2;
        an+=1ll*q[1]*(q[1]-1)/2;
    }
    for(iter it=ma[odd].begin(); it!=ma[odd].end(); it++)
    {
        int va=(*it).first, qq=(*it).second;
        int nva=(xo[odd]^va);
        iter it2=ma[ev].find(nva);
        if(it2!=ma[ev].end())
        {
            int qq2=(*it2).second;
            an+=1ll*qq*qq2;
        }
    }
    cout<<an;
}