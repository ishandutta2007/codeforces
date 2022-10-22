#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> vec[i];

	int j = 1;
	while (j < n && vec[j] == vec[0])	j++;

	for (int i = j + 1; i < n; i++){
		if (vec[i] > vec[j] && vec[j] < vec[0]){
			cout << "3\n";
			cout << "1 " << j + 1 << " " << i + 1 << "\n";
			return 0;
		}
		if (vec[i] < vec[j] && vec[j] > vec[0]){
			cout << "3\n";
			cout << "1 " << j + 1 << " " << i + 1 << "\n";
			return	0;
		}

		j = i;
	}
	cout << "0\n";
	return	0;
}