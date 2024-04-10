#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=600+5;
int q,n,m;
int v[N][N];

inline bool hlf()
{
    if(n%2==1)
    {
        return 0;
    }
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
        int a=v[1][j];
        int b=v[n][j];
        if(abs(a-b)<=10)
        {
            cnt++;
        }
    }
  ///  cout<<"\t\t"<<cnt<<" "<<m<<"\n";
    if(cnt<=m/2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //  freopen("data","r",stdin);
  //  freopen("OUTPUT","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>v[i][j];
            }
        }
        if(hlf())
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
/**


**/