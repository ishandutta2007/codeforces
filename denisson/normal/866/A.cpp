#include <bits/stdc++.h>
		
using namespace std;
		
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double



int main(){ 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("heavy.in", "r", stdin);
	//freopen("heavy.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) cout << "1 1\n1", exit(0);
	cout << (n - 1) * 2 << ' ' << 2 << "\n" << 1 << ' ' << 2;
}