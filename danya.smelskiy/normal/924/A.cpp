#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 100 + 11;

char a[N][N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            use[j]=0;
        for (int j=1; j<=m; j++)
            if (a[i][j]=='#')
            {
                for (int k=1; k<=n; k++)
                    if (a[k][j]=='#') use[k]=1;
                break;
            }
        for (int j=1; j<=m; j++)
        if (a[i][j]=='#')
        {
            for (int k=1; k<=n; k++)
            if (a[k][j]=='#'&&use[k]==0) {cout<<"No"<<endl; return 0;} else
            if (a[k][j]=='.'&&use[k]==1) {cout<<"No"<<endl; return 0;}
        }
    }
    cout<<"Yes"<<endl;

}