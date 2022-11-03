#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 111;

int n,m;
int k[N],a[N][N];
bool us[N][N];
bool used[N];

void dfs(int v)
{
    used[v]=true;
    for (int i=0; i<n; i++)
        if (!used[i] && us[v][i])
            dfs(i);
}

int main()
{
    cin >> n >> m;
    int sum =0;
    for (int i=0; i<n; i++)
    {
        cin >> k[i];
        for (int j=0; j<k[i]; j++)
            cin >> a[i][j];
        sum+=k[i];
    }
    for (int i=0; i<n; i++)
    {
        used[i]=false;
        for (int j=0; j<n; j++)
            us[i][j]=false;
    }
    for (int v1=0; v1<n; v1++)
        for (int v2=v1+1; v2<n; v2++)
            for (int i=0; i<k[v1]; i++)
                for (int j=0; j<k[v2]; j++)
                    if (a[v1][i]==a[v2][j])
                        us[v1][v2]=us[v2][v1]=true;
    int ans=0;
    for (int i=0; i<n; i++)
        if (!used[i])
        {
            ans++;
            dfs(i);
        }
    if (sum!=0)ans--;
    cout << ans << endl;
    return 0;
}