#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> P;
#define INF (1 << 29)
P goal;
string m[1050];
int start;
int res ;
int xs[] = {0, 1, 0, -1}, ys[] = {1, 0, -1, 0};
int dist[1050][1050];
int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 0;i < r;i++){
	cin >> m[i];
	for(int j = 0;j < m[i].size();j++){
	    if(m[i][j] == 'E')goal = P(i, j);
	    dist[i][j] = INF;
	}
    }
    queue<P> q;  
    dist[goal.first][goal.second] = 0;
    q.push(goal);
    while(!q.empty()){
	for(int i = q.size();i--;){
	    P tmp = q.front();q.pop();
	    for(int j = 0;j < 4;j++){
		int x = tmp.first + xs[j], y = tmp.second + ys[j];
		if(x < 0 || r <= x || y < 0 || c <= y)continue;
		if(m[x][y] == 'T')continue;
		if(dist[x][y] != INF)continue;
		dist[x][y] = dist[tmp.first][tmp.second] + 1;
		q.push(P(x, y));
		if(m[x][y] == 'S'){
		    start = dist[x][y];
		}
	    }
	}
    }
    for(int i = 0;i < r;i++)
	for(int j = 0;j < c;j++)
	    if(m[i][j] > '0' && m[i][j] <= '9' && dist[i][j] <= start){res += m[i][j]-'0';}
    cout << res << endl;
    return 0;
}