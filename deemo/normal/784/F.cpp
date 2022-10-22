#include<iostream>

using namespace std;

const int MAXN = 120;

int n, a[MAXN];
//asd

int main(){
	cin >> n;
	int x = 1;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			for (int w = 0; w < 1000; w++)
				x = x * i^j;
	a[0] = x;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < n; j++)
			if (a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}