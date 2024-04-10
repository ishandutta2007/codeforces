//challenge accepted :)

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 40;

int n, m;
int vec[MAXN], a[MAXN], b[MAXN];
int c1, c2, cnt;
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		char ch;	cin >> ch >> vec[i];
		if (ch == '-')	vec[i] *= -1;
		if (ch == '+'){
			a[vec[i]]++;
			c1++;
		}
		else{
			b[-vec[i]]++;
			c2++;
		}
	}
	for (int i = 1; i <= n; i++){
		int temp = a[i] + (c2 - b[i]);
		if (temp == m){
			mark[i] = 1;
			cnt++;
		}
	}

	for (int i = 1; i <= n; i++){
		bool tr = 0, li = 0;
		if (vec[i] > 0){
			if (mark[vec[i]])	tr = 1;
			if (cnt - mark[vec[i]] != 0)	li = 1;
		}
		else{
			if (mark[-vec[i]])	li = 1;
			if (cnt - mark[-vec[i]] != 0)	tr = 1;
		}

		if (tr && li)
			cout << "Not defined\n";
		else if (tr)
			cout << "Truth\n";
		else if (li)
			cout << "Lie\n";
		else	assert(0);
	}
	return 0;
}