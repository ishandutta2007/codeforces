#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/// typedef long double ld;

const int M=50+7;
const int N=(int)1e4+7;

int m,n;
bool buga[M][N];

void ex(bool e)
{
        if(e) cout<<"possible\n";
        else cout<<"impossible\n";
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
                int ln;
                cin>>ln;
                for(int j=1;j<=ln;j++)
                {
                        int x;
                        cin>>x;
                        buga[i][x]=1;
                }
        }
        for(int a=1;a<=m;a++)
        {
                for(int b=a+1;b<=m;b++)
                {
                        bool only=1;
                        for(int j=1;j<=n;j++)
                        {
                                if(buga[a][j]==1 && buga[b][j]==1)
                                {
                                        only=0;
                                }
                        }
                        if(only)
                        {
                                ex(0);
                        }
                }
        }
        ex(1);
        return 0;
}
/**

**/