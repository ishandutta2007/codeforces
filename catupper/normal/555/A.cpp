#include<iostream>
#include<algorithm>

using namespace std;

int n, k, m, cnt, res;
int x[108000];
int main(){
	cin >> n >> k;
	for(int i = 0;i < k;i++){
		cin >> m;
		for(int j = 0;j < m;j++){
			cin >> x[j];
		}
		for(int j = 0;j < m;j++){
			if(x[j] == j + 1)res++;
			else break;
		}
		cnt += m-1;
	}
	cnt -= res-1;
	cout << n - res + cnt << endl;
	return 0;
}