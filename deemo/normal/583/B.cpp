#include<iostream>

using namespace std;

int n;
int a[2000];
bool mark[2000];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0)
			for (int j = 0; j < n; j++){
				if (mark[j])	continue;
				if (sum < a[j])	continue;
				sum++;
				mark[j] = 1;
			}
		else
			for (int j = n-1; j >= 0; j--){
				if (mark[j])	continue;
				if (sum < a[j])	continue;
				sum++;
				mark[j] = 1;
			}
		if (sum == n){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}