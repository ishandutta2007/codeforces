#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
#define sz size()
#define mp(a,b) make_pair(a,b)
#define LOOP(_index,_times) for(int _index = 0; _index<_times;_index++)
#define FOR(_index,_start,_end) for(int _index=_start;_index<_end;_index++)
#define FORE(_index,_start,_end) for(int _index=_start;_index<=_end;_index++)
#define INF 10000
vector<int> v[100];
void bfs(int start,int *dis,double *way)
{
    for(int k=0;k<100;k++) dis[k] = INF;
    dis[start] = 0;
    queue<int> Q;
    Q.push(start);
    way[start] = 1;
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for(int k = 0; k < v[x].size(); k++)
        {
            if(dis[ v[x][k] ] > dis[x] + 1)
            {
                dis[v[x][k]] = dis[x] + 1;
                way[v[x][k] ] = way[x];
                Q.push( v[x][k] );
            }
            else if(dis[ v[x][k] ] == dis[x] + 1)
            {
                way[v[x][k] ] += way[x];
            }
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int k=0;k<m;k++)
    {
        cin >> a >> b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int fd[100],bd[100];
    double fw[100] = {0}, bw[100] = {0};

    bfs(0,fd,fw);
    bfs(n-1,bd,bw);


    int dis = fd[n-1];
    double ans = 0; // 

    for(int k=1;k<n-1;k++) // 
    {
        if(fd[k] + bd[k] == dis && fw[k] / fw[n-1] * bw[k] > ans) // 
        {
            ans = fw[k] / fw[n-1] * bw[k];
        }
    }
    printf("%.12f",max(ans*2,1.));
    return 0;
}