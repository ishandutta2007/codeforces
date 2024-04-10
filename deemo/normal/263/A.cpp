#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int x, y;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++){
			int a;	cin >> a;
			if (a == 1){
				x = i, y = j;
			}
		}
	cout << abs(x - 2) + abs(y - 2) << endl;
	return	0;
}