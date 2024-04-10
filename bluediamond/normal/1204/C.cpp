#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
const int M=(int)1e6+7;
const int inf=(int)1e9;
int n;
vector <int> g[N];
int k;
int a[M];
int d[N][N];
int b[M],tp;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n;
        for(int i=1;i<=n;i++)
        {
                string s;
                cin>>s;
                for(int j=1;j<=n;j++)
                        if(s[j-1]=='1')
                        {
                                g[i].push_back(j);
                                d[i][j]=1;
                        }
                        else
                                d[i][j]=inf;
                d[i][i]=0;
        }
        for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++)
                        for(int j=1;j<=n;j++)
                                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

        cin>>k;
        for(int i=1;i<=k;i++)
                cin>>a[i];
        b[++tp]=a[1];
        int i=2;
        while(i<=k)
        {
                int j=i;
                while(j+1<=k && d[b[tp]][a[j+1]]==d[b[tp]][a[j]]+1)
                        j++;
                b[++tp]=a[j];
                i=j+1;
        }

        cout<<tp<<"\n";
        for(int i=1;i<=tp;i++)
                cout<<b[i]<<" ";
        cout<<"\n";

        return 0;
}
/**

**/