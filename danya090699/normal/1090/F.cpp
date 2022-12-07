#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=3e9;
int que(int x, int y, int z)
{
    cout<<"? "<<x+1<<" "<<y+1<<" "<<z+1<<endl;
    int re;
    cin>>re;
    return re;
}
int su[5][5];
bool comp(int a, int b)
{
    for(int i=0; i<5; i++)
    {
        if(i!=a and i!=b)
        {
            int vaa=su[b][i], vab=su[a][i];
            if(vaa<vab) return true;
        }
    }
    return false;
}
main()
{
    int n, x1, x2, ar[5];
    cin>>n;
    for(int a=0; a<5; a++)
    {
        ar[a]=a;
        for(int b=a+1; b<5; b++)
        {
            vector <int> sp;
            for(int c=0; c<5; c++) if(c!=a and c!=b) sp.push_back(c);
            su[a][b]=que(sp[0], sp[1], sp[2]);
            su[b][a]=su[a][b];
        }
    }
    sort(ar, ar+5, comp);
    x1=ar[3], x2=ar[4];
    int mi=-1, mi2=-1, cuva=inf;
    for(int a=0; a<n; a++)
    {
        if(a!=x1 and a!=x2)
        {
            int va=que(a, x1, x2);
            if(va<cuva) cuva=va, mi=a;
        }
    }
    cuva=inf;
    for(int a=0; a<n; a++)
    {
        if(a!=x1 and a!=x2 and a!=mi)
        {
            int va=que(a, x1, x2);
            if(va<cuva) cuva=va, mi2=a;
        }
    }
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        if(a!=mi and a!=mi2)
        {
            int va=que(a, mi, mi2);
            sp.push_back({va, a});
        }
    }
    int an[n];
    sort(sp.begin(), sp.end());
    int su13=sp[0].first, su15=sp[2].first, su35=que(sp[0].second, sp[1].second, sp[2].second);
    an[mi]=(su13+su15-su35)/2;
    for(int a=0; a<sp.size(); a++) an[sp[a].second]=sp[a].first-an[mi];
    an[mi2]=que(mi2, sp[0].second, sp[1].second)-an[sp[1].second];

    cout<<"! ";
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
    cout<<endl;
}