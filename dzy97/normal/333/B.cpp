#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define cl(x,a) memset(x,a,sizeof(x))
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
struct node
{
    int x,y;
    node(){};
    node(int a,int b):x(a),y(b){};
}a[10];
    static bool map[1010][1010];
    int n,m;
double abs(double a)
{
    return a>=0?a:-a;//! return debug
}
  
bool ok(node a,node b)
{
    if(map[a.x][a.y] || map[b.x][b.y]) return 0;
    if( (a.x == 1 || a.x == n) && a.y == b.y) return 0;
    if( (a.y == 1 || a.y == n) && a.x == b.x) return 0;
  
    if(a.x == b.x || a.y - b.y) return 1;
    double tmp = abs(a.y - b.y)/abs(a.x - b.x);
    double t = fabs(tmp -1);
    if(fabs(tmp - 1) <0.000001) return 0;
    return 1;
}
  
int g[10];
int maxv;
void DFS(int dep,int st)
{
    if(dep > 4)
    {
        maxv =4;
        return;
    }
  
    for(int i = st;i <= 8;i++) if (!map[a[i].x][a[i].y])//! 
    {
        g[dep] = i;
        int j;
        for(j = 1;j < dep;j++)
            if(!ok(a[g[j]],a[g[dep]])) break;
  
        if(j == dep)
        {
            maxv = max(maxv,dep);
            DFS(dep+1,i+1);
        }
    }
}
  
int main()
{
    cin>>n>>m;
    memset(map,0,sizeof(map));
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        map[x][1] = map[x][n] = map[1][y] = map[n][y] = 1;
    }
    if(n == 2) {cout<<0<<endl;return 0;}
  
    int len = n/2;
    int ans = 0;
    for(int i = 2;i <= len;i++)
    {
        int j = n-i+1;
        a[1] = node(i,1),a[2] = node(j,1);
        a[3] = node(n,i),a[4] = node(n,j);
        a[5] = node(j,n),a[6] = node(i,n);
        a[7] = node(1,j),a[8] = node(1,i);
  
        maxv =0;
        DFS(1,1);
        ans += maxv;
    }
  
    if(n % 2 == 1)
    {
        int mid = n/2+1;
        if(!map[1][mid] || !map[n][mid] || !map[mid][1] || !map[mid][n]) ans++;
    }
    cout<<ans<<endl;
  
    return 0;
}