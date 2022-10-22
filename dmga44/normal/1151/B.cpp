#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 505

vector<int> a[MAXN];
int aa[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> x;
            aa[i][j]=x;
            if(!a[i].size() || a[i][0]!=x)
                a[i].push_back(x);
        }

    x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        x=max(x,(int)a[i].size());
        y^=a[i][0];
    }
    if(x==1 && y==0)
        db("NIE")
    else
    {
        db("TAK")
        if(y==0)
        {
            bool ok=0;
            for(int i=0;i<n;i++)
            {
                if(!ok && a[i].size()>1)
                {
                    ok=1;
                    for(int j=0;j<m;j++)
                        if(aa[i][j]==a[i][1])
                        {
                            cout << j+1 << ' ';
                            break;
                        }
                }
                else
                    for(int j=0;j<m;j++)
                        if(aa[i][j]==a[i][0])
                        {
                            cout << j+1 << ' ';
                            break;
                        }
            }
        }
        else
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(aa[i][j]==a[i][0])
                    {
                        cout << j+1 << ' ';
                        break;
                    }
        cout << '\n';
    }


    return 0;
}