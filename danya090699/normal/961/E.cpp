#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int fen[sz];
void cha(int p, int va)
{
    while(p<sz)
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int que(int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    vector <int> ve[n];
    long long an=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a]=min(ar[a], n);
        ve[ar[a]-1].push_back(a+1);
        if(ar[a]>=a+1) an--;
    }
    for(int a=0; a<n; a++)
    {
        cha(ar[a], 1);
        for(int b=0; b<ve[a].size(); b++) an+=(a+1)-que(ve[a][b]-1);
    }
    cout<<an/2;
}