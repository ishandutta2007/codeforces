#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 40;

int n;
int vec[MAXN];
int mark[MAXN];
ll sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];

	ll sum = vec[n - 1];
	mark[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--){
		if (sum >= 0){
			sum -= vec[i];
			mark[i] = -1;
		}
		else{
			sum += vec[i];
			mark[i] = 1;
		}
	}
	if (sum < 0)
		for (int i = 0; i < n; i++)
			mark[i] *= -1;

	for (int i = 0; i < n; i++)
		if (mark[i] == 1)
			cout << "+";
		else
			cout << "-";
	cout << endl;
	return 0;
}