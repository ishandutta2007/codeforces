#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
int matrix[1000][1000];
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cur = 0;
	for (int i=0; i < n; i += 4){
		for (int j=0; j < n; j += 4){
			for (int k=0; k < 4; k++) for (int e=0; e < 4; e++){
				matrix[i+k][j+e] = cur++;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0; j < n; j++) cout << matrix[i][j] << " ";
		cout << endl;
	}
}