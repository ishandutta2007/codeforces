#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 5;

int n;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int mn = 1e9, ind = -1;
	for (int i = 0; i < n; i++){
		bool od = 0;
		for (int j = 0; j < n; j++)
			if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j]){
				od = 1;
				break;
			}
		if (!od){
			if (mn > d[i]){
				mn = d[i];
				ind = i + 1;
			}
		}
	}
	cout << ind << "\n";
	return	0;
}