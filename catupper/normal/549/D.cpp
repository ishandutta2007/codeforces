#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, m, res;
string str[1080];
int num[108][108];

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> str[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(str[i][j] == 'B')num[i][j] = 1;
			else num[i][j] = -1;
		}
	}
	for(int i = n -1;i >= 0;i--){
		for(int j = m - 1;j >= 0;j--){
			if(num[i][j] == 0)continue;
			res++;
			int tmp = num[i][j];
			for(int k = i;k >= 0;k--){
				for(int l = j;l >= 0;l--){
					num[k][l] -= tmp;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}