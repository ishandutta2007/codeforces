#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int n;
int a[216000];
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		a[i] += i;
	}
	sort(a, a + n);
	for(int i = 0;i < n;i++){
		a[i] -= i;
	}
	for(int i = 0;i < n - 1;i++){
		if(a[i] > a[i+1]){
			cout << ":(" << endl;
			return 0;
		}
	}
	for(int i = 0;i < n;i++){
		if(i)cout << " ";
		cout << a[i];
	}                cout << endl;
	return 0;
	
}