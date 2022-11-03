#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 111;

int n,m;

int used[N],path[N][N];
bool found=false;
void findCyrcle(int v,int pr=-1)
{
    used[v]=1;
    for (int i=0; i<n; i++)
        if (path[v][i])
        {
            if (used[i]==0)
                findCyrcle(i,v);
            else
            if (used[i]==1 && i!=pr)
                found=true;
        }
    used[v]=2;
}

int main()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    if (n!=m)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        path[a][b]=path[b][a]=1;
    }
    findCyrcle(0);
    if (!found)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=0; i<n; i++)
        if (!used[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "FHTAGN!" << endl;
    return 0;
}