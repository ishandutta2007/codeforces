#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 111111;

vector<int> a[N];
int ans[N],n;
bool us[N];

bool find(int x,int y)
{
    for (int i=0; i<4; i++)
        if(a[x][i]==y)
            return true;
    return false;
}

bool check()
{
    for (int i=1; i<=n; i++)us[i]=false;
    us[1]=us[ans[1]]=us[ans[2]]=true;
    for (int i=3; i<n; i++)
    {
        int v1=ans[i-1];
        int v2=ans[i-2];
        bool found=false;
        for (int j=0; j<4; j++)
        {
            int t=a[v1][j];
            if (!us[t] && find(v2,t))
            {
                ans[i]=t;
                us[t]=true;
                found=true;
                break;
            }
        }
        if (!found)return false;
    }
    return (find(1,ans[n-1])&&find(1,ans[n-2])&&find(ans[1],ans[n-1]));
}

int main()
{
   // ifstream cin("input.txt");
    cin >> n;
    for (int i=0; i<2*n; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1; i<=n; i++)
        if (a[i].size()!=4)
        {
            cout << -1 << endl;
            return 0;
        }
    ans[0]=1;
    for (int i=0; i<4; i++)
    {
        ans[1]=a[1][i];
        for (int j=0; j<4; j++)
            if (i!=j)
            {
                ans[2]=a[1][j];
                if (check())
                {
                    for (int i=0; i<n; i++)
                        cout << ans[i] << " ";
                    cout << endl;
                    return 0;
                }
            }
    }
    cout << -1 << endl;
    return 0;
}