#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 20;

int p[max_n], ask[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int>	vec(n), sec(n);
	for (int i = 0; i < n; i++){
		cin >> vec[i] >> sec[i];
		sec[i] = vec[i] * sec[i];
		if (i != 0)	p[i] = p[i - 1];
		p[i] += sec[i];
	}

	for (int i = 0; i < q; i++)
		cin >> ask[i];

	int b = 0, last = 0;
	for (int i = 0; i < n; i++){
		while (b < q && p[i] >= ask[b]){
			cout << i + 1 << "\n";
			b++;
		}
	}
	return 0;
}