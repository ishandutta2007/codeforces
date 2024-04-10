#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=150000+7;

int n;

int t[N];

int first[N];
int last[N];
int papa[N];

int gt(int a)
{
        if(a==t[a])
        {
                return a;
        }
        else
        {
                t[a]=gt(t[a]);
                return t[a];
        }
}

void uni(int a,int b)
{
        a=gt(a);
        b=gt(b);
        if(a!=b)
        {
                papa[first[a]]=last[b];
                last[b]=last[a];
                t[a]=b;
        }
}

bool viz[N];

int sl[N],top=0;

void dfs(int a)
{
        viz[a]=1;
        if(papa[a]>0 && viz[papa[a]]==0)
        {
                dfs(papa[a]);
        }
        sl[++top]=a;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                first[i]=last[i]=i;
                t[i]=i;
        }
        for(int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                x=gt(x);
                y=gt(y);
                uni(x,y);
        }
        for(int i=1;i<=n;i++)
        {
                if(viz[i]==0)
                {
                        dfs(i);
                }
        }
        for(int i=1;i<=top;i++)
        {
                cout<<sl[i]<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

5
1 4
2 5
3 1
4 5


**/