#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1005

int ma[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int n,a,b;
    cin >> n >> a >> b;
    if(a==1 || b==1)
        if(!(a==1 && b==1 && (n<4 && n>1)))
        {
            int x=max(a,b);
            for(int i=0;i<n-x;i++)
                ma[i][i+1]=ma[i+1][i]=1;
            db("YES")
            if(x==a)
            {
                for(int i=0;i<n;i++,cout << '\n')
                    for(int j=0;j<n;j++)
                        cout << ma[i][j];
            }
            else
            {
                for(int i=0;i<n;i++,cout << '\n')
                    for(int j=0;j<n;j++)
                    {
                        if(i==j)
                            ma[i][j]=1;
                        cout << !ma[i][j];
                    }
            }
            return 0;
        }
    db("NO")

    return 0;
}