#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<functional>

using namespace std;

const int MAX = 5e5;

int c[3][300];
char f[MAX];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s, t;	cin >> s >> t;
	for (int i = 0; i < t.size(); i++)
		c[0][t[i]]++;
	for (int i = 0; i < s.size(); i++)
		c[1][s[i]]++, c[2][s[i]]++;

	int cn = 0, ans = 0, b = 0;
	for (int i = 'A'; i <= 'Z'; i++){
		int rep = c[0][i] - c[1][i];
		for (int j = 0; j < rep; j++){
			ans++;
			bool fl = 1;
			while (fl){
				fl = 0;
				while (c[1][s[b]] <= c[0][s[b]])	c[2][s[b++]]--;
				if (s[b] > i || c[1][s[b]] - c[2][s[b]] >= c[0][s[b]]){
					c[1][s[b]]--;
					c[2][s[b]]--;
					s[b] = i;
					c[1][s[b++]]++;
				}
				else{
					fl = 1;
					c[2][s[b++]]--;
				}
			}
		}	
	}



	cout << ans << endl;
	cout << s << endl;
	return 0;
}