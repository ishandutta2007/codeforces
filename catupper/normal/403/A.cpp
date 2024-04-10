#include<iostream>
#include<algorithm>

using namespace std;

void solve(int n, int p){
	cout << "2 1" << endl;
	cout << "3 1" << endl;
	cout << "3 2" << endl;
	cout << "4 1" << endl;
	cout << "4 2" << endl;
	cout << "4 3" << endl;
	cout << "5 1" << endl;
	cout << "5 2" << endl;
	cout << "5 3" << endl;
	cout << "5 4" << endl;
	for(int i = 6;i <= n;i++){
		cout << i << " " << 1 << endl;
		cout << i << " " << 2 << endl;
		for(int j = 3;j < i && p;j++,p--){
			cout << i << " " << j << endl;
		}
	}
}

int main(){
	int n, p, t;
	cin >> t;
	while(t--){
		cin >> n >> p;
		solve(n, p);
	}
	return 0;
}