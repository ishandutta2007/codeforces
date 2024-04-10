#include<iostream>
#include<algorithm>

using namespace std;
int res[1050][1050];
int main(){
	int n;
	cin >> n;
	int p = 0;
	res[1][2] = res[2][1] = 1;
	res[3][2] = res[2][3] = 1;
	res[4][2] = res[2][4] = 1;
	for(int i = 2;i <= 40;i++){
		res[i * 2 - 1][i * 2 + 1] = res[i * 2 + 1][i * 2 - 1] = 1;
		res[i * 2 - 1][i * 2 + 2] = res[i * 2 + 2][i * 2 - 1] = 1;
		res[i * 2][i * 2 + 1] = res[i * 2 + 1][i * 2] = 1;
		res[i * 2][i * 2 + 2] = res[i * 2 + 2][i * 2] = 1;
	}
	int l = 83;
	for(int i = 0;(1 << i) <= n;i++){
		if((1 << i) & n){
			res[0][l] = res[l][0] = 1;
			l++;
			for(int j = 0;j < 38 - i;j++){
				res[l][l - 1] = res[l - 1][l] = 1;
				l++;
			}
			l--;
			res[l][(i + 2) * 2] = res[(i + 2) * 2][l] = 1;
			l++;
		}
	}
	cout << l << endl;
	for(int i = 0;i < l;i++){
		for(int j = 0;j < l;j++){
			if(res[i][j])cout << "Y";
			else cout << "N";
		}
		cout << endl;
	}
	return 0;
}