#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 40;

int n;
string s;
int vec[MAXN];

int main(){
	cin >> n >> s;
	vec[0] = 1;
	for (int i = 1; i < n; i++){
		char ch = s[i - 1];
		if (ch == '=')	
			vec[i] = vec[i - 1];
		else if (ch == 'R')
			vec[i] = vec[i - 1] + 1;
		else{
			if (vec[i - 1] != 1)
				vec[i] = 1;
			else{
				for (int j = i - 1; j >= 0; j--){
					int dif = 0;
					if (j != 0)	dif = abs(vec[j] - vec[j - 1]);
					vec[j]++;
					if (j == 0 || s[j - 1] == 'R' || dif > 1)	break;
				}
				vec[i] = vec[i - 1] - 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}