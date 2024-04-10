#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500000;
int n,mi,dif;
int v[N+5];
int st[N+5],dr[N+5];
bool gata[N+5];
int add[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>mi>>dif;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(int i=1;i+mi-1<=n;i++)
    {
        int start=i+mi-1;
        if(v[start]-v[i]>dif)
        {
            st[i]=dr[i]=-1;
            continue;
        }
        st[i]=start;
        dr[i]=st[i];
        int pas=(1<<19);
        while(pas)
        {
            if(dr[i]+pas<=n && v[dr[i]+pas]-v[i]<=dif)
                dr[i]+=pas;
            pas/=2;
        }
    }
    ///
    gata[0]=1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=add[i];
        if(sum>0)
            gata[i]=1;
        if(gata[i-1]==0 || st[i]==-1)
            continue;
        add[st[i]]++;
        if(st[i]==i)
        {
            sum++;
            if(sum>0)
                gata[i]=1;
        }
        add[dr[i]+1]--;
    }
    if(gata[n]==1)
        puts("YES");
    else
        puts("NO");
    return 0;
}
/**

**/