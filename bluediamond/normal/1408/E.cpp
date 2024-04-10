#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


struct T
{
        int x;
        int y;
        int c;
};

bool operator < (T a,T b)
{
        return a.c>b.c;
}

const int N=(int) 2e5+7;
int m;
int n;
T e[N];
int top;
int a[N];
int b[N];
int t[N];

int r(int x)
{
        if (t[x]==x)
                return x;
        else
                return t[x]=r(t[x]);
}

void u(int x,int y)
{
        t[r(x)]=r(y);
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>m>>n;
        for (int i=1;i<=m;i++)
                cin>>a[i];
        for (int i=1;i<=n;i++)
                cin>>b[i];
        for (int i=1;i<=m;i++)
        {
                int l;
                cin>>l;
                for (int j=1;j<=l;j++)
                {
                        int x;
                        cin>>x;
                        e[++top]={i,m+x,a[i]+b[x]};
                }
        }
        n+=m;
        sort(e+1,e+top+1);
        for (int i=1;i<=n;i++)
                t[i]=i;
        ll sol=0;
        for (int i=1;i<=top;i++)
        {
                if (r(e[i].x)!=r(e[i].y))
                        u(e[i].x,e[i].y);
                else
                        sol+=e[i].c;
        }
        cout<<sol<<"\n";
}