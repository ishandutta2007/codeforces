#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
bool visited[N];
int a[N];

int DFS(int x){
	visited[x] = true;
	if (visited[a[x]]){
		return a[x];
	}else
		DFS(a[x]);
}

int32_t main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			visited[j] = false;
		cout << DFS(i) << ' ';
	}
}