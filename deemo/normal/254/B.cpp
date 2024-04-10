#include<fstream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int C = 500;

int x[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int z[3 * C];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;	cin >> n;
	while (n--){
		int m, d, p, t;	cin >> m >> d >> p >> t;	m--, d--;
		int tm = C;
		for (int i = 0; i < m; i++)
			tm += x[i];
		tm += d;
		for (int j = tm - 1; j >= tm - t; j--)
			z[j] += p;
	}	
	int ans = 0;
	for (int i = 0; i < 3 * C; i++)
		ans = max(ans, z[i]);
	cout << ans << endl;
	return 0;
}