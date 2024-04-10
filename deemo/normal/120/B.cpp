#include<fstream>
#include<string>

using namespace std;

const int MAXN = 1e3 + 200;

int n, k;
int mark[MAXN];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> k;	k--;
	for (int i = 0; i < n; i++)	cin >> mark[i];
	while (!mark[k])	k = (k + 1) % n;
	cout << k + 1 << endl;
	return 0;
}