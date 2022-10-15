#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500+7;

int n,m;
int a[N][N];
int b[N][N];
int v[N][N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        cin>>a[i][j];
                }
        }
       /// cout<<"\n\n";
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        cin>>b[i][j];
                        if(a[i][j]!=b[i][j])
                        {
                                v[i][j]=1;
                        }
                       // cout<<v[i][j]<<" ";
                }
               // cout<<"\n";
        }
        for(int i=1;i<=n;i++)
        {
                vector<int>p;
                for(int j=1;j<=m;j++)
                {
                        if(v[i][j])
                        {
                                p.push_back(j);
                        }
                }
                if(p.size()>0 && i==n)
                {
                        cout<<"No\n";
                        return 0;
                }
                if(p.size()%2==1)
                {
                        cout<<"No\n";
                        return 0;
                }
                for(int j=0;j<(int)p.size();j+=2)
                {
                        int a=p[j];
                        int b=p[j+1];
                        v[i][a]=1-v[i][a];
                        v[i][b]=1-v[i][b];
                        v[i+1][a]=1-v[i+1][a];
                        v[i+1][b]=1-v[i+1][b];
                }
        }
        cout<<"Yes\n";
        return 0;
}
/**

**/