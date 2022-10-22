#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

char c[10][10];
char d[10][10];

void init(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			d[i][j] = 'W';
}

int cnt(int x){
	int ret = 0;
	while (x){
		if (x & 1)	ret++;
		x >>= 1;
	}
	return	ret;
}

int main(){
    for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> c[i][j];
	int z = (1 << 16);
	int ans = 100;
	for (int i = 0; i < z; i++){
		init();
		for (int j = 0; j < 8; j++)
			if ((i >> j) & 1)
				for (int w = 0; w < 8; w++)
					d[j][w] = 'B';
		for (int j = 0; j < 8; j++)
			if ((i >> (j + 8)) & 1)
				for (int w = 0; w < 8; w++)
					d[w][j] = 'B';

		int fl = 0;
		for (int j = 0; j < 8; j++)
			for (int w = 0; w < 8; w++)
				if (d[j][w] != c[j][w])	fl = 1;
		if (fl)	continue;
		ans = min(ans, cnt(i));
	}
	cout << ans << endl;
	return 0;
}