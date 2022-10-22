#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n, q;
int pos[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		pos[temp] = i;
	}
	cin >> q;
	ll c1 = 0, c2 = 0;
	while (q--){
		int temp;	cin >> temp;
		temp = pos[temp];
		c1 += temp + 1;
		c2 += n - temp;
	}
	cout << c1 << " " << c2 << endl;
	return 0;
}