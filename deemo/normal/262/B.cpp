#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n, k;
int vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	int b = 0;
	while (b < n && k--){
		if (vec[b] >= 0){
			k++;
			break;
		}
		vec[b++] *= -1;
	}
	if (k < 0)	k = 0;
	sort(vec, vec + n);
	if (vec[0] == 0 || k % 2 == 0){
		ll sum = 0;
		for (int i = 0; i < n; i++)	sum += vec[i];
		cout << sum << endl;
		return 0;
	}
	
	vec[0] *= -1;
	ll sum = 0;
	for (int i = 0; i < n; i++)	sum += vec[i];
	cout << sum << endl;
	return 0;
}