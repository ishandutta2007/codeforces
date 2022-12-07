#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int q[sz], cq=0;
vector <int> st[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, c, cq, an=0;
    cin>>n>>c;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ar[a]=x;
        q[x]++;
        st[x].push_back(q[x]-q[c]);
        //cout<<q[x]-q[c]<<" ";
    }
    cq=q[c];
    for(int a=0; a<sz; a++)
    {
        if(st[a].size())
        {
            reverse(st[a].begin(), st[a].end());
            for(int b=0; b+1<st[a].size(); b++) st[a][b+1]=max(st[a][b+1], st[a][b]);
        }
        q[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x=ar[a];
        int be=st[x].back();
        int cu=(be-q[x]+q[c])+cq;
        an=max(an, cu);
        q[x]++;
        st[x].pop_back();
    }
    cout<<an;
}