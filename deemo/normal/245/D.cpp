#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int n;	cin >> n;
	for (int i = 0; i < n; i++){
		int x = 0;
		for (int j = 0; j < n; j++){
			int temp;	cin >> temp;
			if (i == j)	continue;
			x |= temp;
		}
		cout << x << " ";
	}
	cout << endl;
	return 0;
}