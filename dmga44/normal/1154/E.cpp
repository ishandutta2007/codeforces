#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 200005

int a[MAXN],p[MAXN][2],mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    priority_queue<pii,vector<pii>,less<pii> > pq;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pq.push(pii(a[i],i));
    }

    for(int i=0;i<n;i++)
    {
        p[i][0]=-1;
        p[i][1]=-1;
        if(i)
            p[i][0]=i-1;
        if(i<n-1)
            p[i][1]=i+1;
    }

    int t=1;
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();
        int pos=x.second;
        if(mk[pos])
            continue;
        mk[pos]=t;
        int p1=pos,p2=pos,moves=0;
        while(p[p1][0]!=-1 && moves<k)
        {
            p1=p[p1][0];
            mk[p1]=t;
            moves++;
        }

        moves=0;
        while(p[p2][1]!=-1 && moves<k)
        {
            p2=p[p2][1];
            mk[p2]=t;
            moves++;
        }
        if(p[p1][0]!=-1)
            p[p[p1][0]][1]=p[p2][1];
        if(p[p2][1]!=-1)
            p[p[p2][1]][0]=p[p1][0];

        t=3-t;
    }

    for(int i=0;i<n;i++)
        cout << mk[i];

    return 0;
}