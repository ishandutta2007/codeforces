#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> P;
long long fo[55], ft[55], tt[55], one[55], two[55], k, x, n, m;

int main(){
	one[1] = 1;
	two[2] = 1;
	tt[3] = 1;
	one[3] = 1;
	two[3] = 1;
	cin >> k >> x >> n >> m;
	for(int i = 4;i <= k;i++){
		one[i] = one[i - 1] + one[i - 2];//12
		two[i] = two[i - 1] + two[i - 2];//34
		tt[i] = tt[i - 1] + tt[i - 2];
		fo[i] = fo[i - 1] + fo[i - 2];
		ft[i] = ft[i - 1] + ft[i - 2];
		if(i % 2 == 0)fo[i]++;
		else ft[i]++;
	}
	
	for(int i = 0;2 * i <= n;i++){
		if(i * one[k] > 1e9)continue;
		for(int j = 0;2 * j <= m;j++){
			if(j * two[k] > 1e9)continue;
			if(i * one[k] + j * two[k] == x){
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i;l++)cout <<"X";
				cout << endl;
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j;l++)cout << "X";
				cout << endl;
				return 0;
			}
			if(2 * i != n && 2 * j != m && i * one[k] + j * two[k] == x - fo[k]){
				cout << "C";
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i - 1;l++)cout << "X";
				cout << endl;
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 1;l++)cout << "X";
				cout << "A" << endl;
				return 0;
			}
			if(2 * j <= m - 2 && i * one[k] + j * two[k] == x - ft[k]){
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i;l++)cout << "X";
				cout << endl;
				cout << "C" ;
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 2;l++)cout << "X";
				cout << "A" << endl;
				return 0;
			}
			if(2 * i != n && 2 * j != m && i * one[k] + j * two[k] == x - tt[k]){
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i - 1;l++)cout <<"X";
				cout << "A";
				cout << endl;
				cout << "C";
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 1;l++)cout << "X";
				cout << endl;
				return 0;				
			}
			if(2 * i <= n - 2 && 2 * j <= m - 2 && i * one[k] + j * two[k] == x - fo[k] - tt[k] - ft[k]){
				cout << "C";
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i - 2;l++)cout <<"X";
				cout << "A";
				cout << endl;
				cout << "C";
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 2;l++)cout << "X";
				cout << "A";
				cout << endl;
				return 0;

			}
			if(2 * i <= n - 1 && 2 * j <= m - 2 && i * one[k] + j * two[k] == x - fo[k] - ft[k]){
				cout << "C";
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i - 1;l++)cout <<"X";
				cout << endl;
				cout << "C";
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 2;l++)cout << "X";
				cout << "A";
				cout << endl;
				return 0;
			}
			if(2 * i <= n - 1 && 2 * j <= m - 2 && i * one[k] + j * two[k] == x - tt[k] - ft[k]){
				for(int l = 0;l < i;l++)cout << "AC";
				for(int l = 0;l < n - 2 * i - 1;l++)cout <<"X";
				cout << "A";
				cout << endl;
				cout << "C";
				for(int l = 0;l < j;l++)cout << "AC";
				for(int l = 0;l < m - 2 * j - 2;l++)cout << "X";
				cout << "A";
				cout << endl;
				return 0;
			}
		}
	}
	cout << "Happy new year!" << endl;
	return 0;
}