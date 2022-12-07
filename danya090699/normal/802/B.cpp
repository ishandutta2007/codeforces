#include <bits/stdc++.h>
using namespace std;
struct el
{
    int nu, ne;
    bool operator < (const el b) const
    {
        if(ne!=b.ne) return(ne>b.ne);
        else return (nu>b.nu);
    }
};
el nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0, inf=1e9;
    cin>>n>>k;
    vector <int> nex[n];
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
    }
    for(int a=n-1; a>=0; a--)
    {
        nex[ar[a]].push_back(a);
    }
    set <el> av;
    for(int a=0; a<n; a++)
    {
        nel.nu=ar[a], nel.ne=inf;
        //if(nex[ar[a]].size()>0) nex[ar[a]].pop_back();
        if(nex[ar[a]].size()>0) nel.ne=nex[ar[a]].back();
        if(av.find(nel)==av.end())
        {
            an++;
            if(av.size()==k) av.erase(av.begin());
        }
        else av.erase(nel);
        nel.ne=inf;
        if(nex[ar[a]].size()>0) nex[ar[a]].pop_back();
        if(nex[ar[a]].size()>0) nel.ne=nex[ar[a]].back();
        av.insert(nel);
    }
    cout<<an;
}