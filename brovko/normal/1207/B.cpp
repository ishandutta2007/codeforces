#include <iostream>
#include <vector>

using namespace std;
int n, m, a[55][55], b[55][55], f;
vector <pair <int, int> > ans;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> a[i][j];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
    {
        if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1)
        {
            b[i][j]=1;
            b[i+1][j]=1;
            b[i][j+1]=1;
            b[i+1][j+1]=1;
            ans.push_back(make_pair(i+1, j+1));
        }
    }
    f=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(a[i][j]!=b[i][j])
        f=0;
    if(f==0)
        cout << -1;
    else
    {
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}