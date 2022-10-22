#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 30;

int n, k;
int b[MAXN], a[MAXN];
bool mark[MAXN];

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!mark[j] && b[j] == 0){
				a[i] = j;
				mark[j] = 1;
				for (int w = 0; w < j; w++)
					if (w + k <= j)
						b[w]--;
				break;
			}
	for (int i = 0; i < n; i++)
		cout << a[i] + 1 << " ";
	cout << endl;
	return 0;
}