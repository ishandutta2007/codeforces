#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

const int MAXN = 1e5 + 20;

int n, mini = 1e9;
int vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		int m;	cin >> m;
		while (m--){
			int temp;	cin >> temp;
			mini = min(mini, temp);
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	int pay = 0;
	for (int i = n - 1; i >= 0;){
		int j = i;
		for (; j >= 0 && j > i - mini; j--)
			pay += vec[j];
		i = j - 2;
	}
	cout << pay << endl;
	return 0;
}