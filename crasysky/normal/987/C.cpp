#include <iostream>
using namespace std;
int a[10004], c[10004];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	int mn = -1;
	for (int i = 2; i < n; ++ i){
		int t1 = -1;
		for (int j = 1; j < i; ++ j)
			if (a[j] < a[i] && (t1 == -1 || c[j] < t1))
				t1 = c[j];
		int t2 = -1;
		for (int j = i + 1; j <= n; ++ j)
			if (a[j] > a[i] && (t2 == -1 || c[j] < t2))
				t2 = c[j];
		if (t1 != -1 && t2 != -1 && (mn == -1 || t1 + t2 + c[i] < mn))
			mn = t1 + t2 + c[i];
	}
	cout << mn << endl;
}