#include<iostream>

using namespace std;

int a[2000000];

int main(){
	int n;	cin >> n;
	int mx = 0, ind = -1;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		a[x]++;
		if (a[x] > mx){
			mx = a[x];
			ind = x;
		}
	}
	cout << ind << "\n";
	return	0;
}