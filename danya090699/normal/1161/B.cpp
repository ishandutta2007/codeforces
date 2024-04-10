#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(u-v);
        if(sv[u].back()<0) sv[u].back()+=n;
        sv[v].push_back(v-u);
        if(sv[v].back()<0) sv[v].back()+=n;
    }
    map <vector <int>, int> mp;
    int ar[n*2];
    for(int a=0; a<n; a++)
    {
        sort(sv[a].begin(), sv[a].end());
        if(mp.find(sv[a])==mp.end()) mp[sv[a]]=mp.size()-1;
        ar[a]=mp[sv[a]];
        ar[a+n]=ar[a];
    }
    int zf[n*2], l=0, r=-1;
    zf[0]=0;
    for(int a=1; a<n*2; a++)
    {
        zf[a]=0;
        if(r>=a) zf[a]=min(zf[a-l], r-a+1);
        while(a+zf[a]<n*2)
        {
            if(ar[zf[a]]==ar[a+zf[a]]) zf[a]++;
            else break;
        }
        if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;

        if(a<n and zf[a]>=n)
        {
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
}