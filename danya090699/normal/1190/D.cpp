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
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2];
    map <int, int> sex;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ar[a][0], &ar[a][1]);
        sex[ar[a][0]]=0;
    }
    int m=0;
    for(auto it=sex.begin(); it!=sex.end(); it++) (*it).second=m++;
    map <int, vector <int> > may;
    int q[m];
    for(int a=0; a<m; a++) q[a]=0, cha(a, 1);
    for(int a=0; a<n; a++)
    {
        ar[a][0]=sex[ar[a][0]];
        q[ar[a][0]]++;
        may[ar[a][1]].push_back(ar[a][0]);
    }
    long long an=0;
    for(auto it=may.begin(); it!=may.end(); it++)
    {
        vector <int> &vec=(*it).second;
        sort(vec.begin(), vec.end());
        int pr=-1, qq=que(m-1);
        for(int a=0; a<vec.size(); a++)
        {
            int i=que(vec[a])-1;
            an+=1ll*(i-pr)*(qq-i);
            pr=i;
        }
        for(int a=0; a<vec.size(); a++)
        {
            q[vec[a]]--;
            if(q[vec[a]]==0) cha(vec[a], -1);
        }
    }
    cout<<an;
}