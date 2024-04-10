#include<iostream>
#include<algorithm>

using namespace std;
#define INF (1 << 25)
int dist[410][410];

int main(){
	for(int i = 0;i < 410;i++)
		for(int j = 0;j < 410;j++)
			dist[i][j] = INF;
	int n, m;
	char c;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> c;
		for(int j = 0;j < m - 1;j++){
			if(c == '>')
				dist[i * m + j][i * m + j + 1] = 1;
			else
				dist[i * m + j + 1][i * m + j] = 1;
		}			
	}
	for(int i = 0;i < m;i++){
		cin >> c;
		for(int j = 0;j < n - 1;j++){
			if(c == 'v')
				dist[j * m + i][(j + 1) * m + i] = 1;
			else
				dist[(j + 1) * m + i][j * m + i] = 1;
		}			
	}
	for(int i = 0;i < n * m;i++){
		for(int j = 0;j < n * m;j++){
			for(int k = 0;k < n * m;k++){
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	for(int i = 0;i < n * m;i++){
		for(int j = 0;j < n * m;j++){
			if(i == j)continue;
			if(dist[i][j] == INF){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}