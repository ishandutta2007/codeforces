#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 10 + 2;

int n, x;
int w[MAXN][MAXN], d[MAXN][MAXN];

void f(int k){
	int z = 0;
op1:
	z<n*n?({d[z/n][z%n] = min(d[z/n][z%n], d[z/n][k] + d[k][z%n]); z++; goto op1; 0;}):1;
}

int main(){
	cin >> n;
	int z = 0;
inp:
	z<n*n?({cin >> w[z/n][z%n]; d[z/n][z%n] = w[z/n][z%n]; z++; goto inp; 1;}):1;

	int k = 0;
it1:
	k<n?({f(k); k++; goto it1; 1;}):1;

	int ans = 0;
	z = 0;
get1:
	z<n*n?({ans = max(ans, d[z/n][z%n]); z++; goto get1; 0;}):1;
	
	cout << ans << "\n";
	return	0;
}