#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 4;

int n, d;
bool fl[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < d; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < n; j++)
			if (temp[j] == '0')
				fl[i] = 1;
	}	
	int ans = 0, cur = 0;
	for (int i = 0; i < d; i++){
		if (!fl[i]){
			cur = 0;
			continue;
		}
		cur++;
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}