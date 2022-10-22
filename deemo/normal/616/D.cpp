#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int MAXN = 2e6 + 5;

int n, vec[MAXN], k;
int c[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);

	int aa = 0, bb = 0;
	int l = 0, r = 0, g = 0;
	for (int i = 0; i < n; i++){
		while (g >= k){
			c[vec[l]]--;
			if (c[vec[l]] == 0)	g--;
			l++;
		}

		while (r < n && g <= k){
			if (c[vec[r]] == 0)	g++;
			c[vec[r]]++;
			r++;
		}
		if (g > k){
			c[vec[--r]]--;
			g--;
		}

		if (r - l >= bb - aa){
			aa = l;
			bb = r;
		}
	}
	cout << aa + 1 << " " << bb << endl;
	return	0;
}