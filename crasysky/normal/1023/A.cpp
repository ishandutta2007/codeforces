#include <iostream>
#include <cstdio>
using namespace std;
char s1[1000006], s2[1000006];
int main(){
	int n, m;
	cin >> n >> m;
	if (n - 1 > m){
		cout << "NO" << endl;
		return 0;
	}
	scanf("%s %s", s1, s2);
	for (int i = 0; i < n; ++ i)
		if (s1[i] == '*'){
			for (int j = i + 1; j < n; ++ j)
				if (s1[j] != s2[m - (n - 1 - (i + 1) + 1) + (j - i - 1)]){
					cout << "NO" << endl;
					return 0;
				}
			cout << "YES" << endl;
			return 0;
		}
		else if (i >= m || s1[i] != s2[i]){
			cout << "NO" << endl;
			return 0;
		}
	if (n != m)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}