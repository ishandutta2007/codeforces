#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, m;

string str[maxn];
int c[maxn];

bool cmp(int x, int y){
	for(int i=0;i<m;i++){
		if(str[x][i] != str[y][i]){
			if(i & 1){
				return str[x][i] > str[y][i];
			}else{
				return str[x][i] < str[y][i];
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	cin >> n >> m;

	for(i=1;i<=n;i++){
		cin >> str[i];
		c[i] = i;
	}

	sort(c + 1, c + n + 1, cmp);

	for(i=1;i<=n;i++){
		cout << c[i] << " ";
	}
	cout << "\n";

	return 0;
}