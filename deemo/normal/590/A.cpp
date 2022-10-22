#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5e5 + 20;

int n, a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> a[i], b[i] = a[i];
	
	int mx = 0;
	for (int i = 1; i < n - 1;)
		if (a[i] != a[i - 1] && a[i] != a[i + 1]){
			int j = i;
			while (j < n - 1 && a[j + 1] != a[j])	j++;
			mx = max(mx, (j - i)/ 2 + bool((j - i) % 2));
			if ((j - i) % 2 == 1)
				for (; i <= j; i++)	b[i] = b[i - 1];
			else{
				int sz = (j - i)/ 2;
				for (int w = 0; w < sz; w++, i++)
					b[i] = b[i - 1];
				for (; i < j; i++)
					b[i] = a[j];
			}
				
		}
		else i++;

	cout << mx << "\n";
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << "\n";
	return	0;
}