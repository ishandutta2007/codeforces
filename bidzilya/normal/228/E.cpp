#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int MAX_INT = 1e9;

int n,m;
int a[100][100];
int us[100];

bool bfs(int v){
     int q[100];
     int uss[100];
     for (int i=0;i<n;i++)uss[i]=us[i];
     int pe=0,ps=0;
     q[0]=v;
     while (ps<=pe){
           int u = q[ps];
           for (int i=0;i<n;i++)
               if (a[u][i]!=-1){
                  if (uss[i]==-1){
                     if (a[u][i]==1)uss[i]=uss[u];
                     if (a[u][i]==0)uss[i]=(uss[u]+1)%2;
                     pe++;
                     q[pe]=i;
                  }else
                  if (a[u][i]==1 && uss[i]!=uss[u] ||
                      a[u][i]==0 && uss[i]==uss[u])
                                 return false;              
               }
           ps++;
     }
     for (int i=0;i<n;i++)us[i]=uss[i];
     return true;
}

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]=-1;
    for (int i=0;i<m;i++){
        int v1,v2,cl;
        cin >> v1 >> v2 >> cl;
        v1--;v2--;
        a[v1][v2]=cl;
        a[v2][v1]=cl;
    }
    for (int i=0;i<n;i++)
        us[i] = -1;
    for (int i=0;i<n;i++)
        if (us[i]==-1){
           us[i]=1;
           if (bfs(i))continue;
           us[i]=0;
           if (bfs(i))continue;
           cout << "Impossible" << endl;
           return 0;
        }
    vector<int> ans;
    for (int i=0;i<n;i++)
        if (us[i]==1)
           ans.push_back(i+1);
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}