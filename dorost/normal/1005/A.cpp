#include <iostream>
using namespace std;
int main(){
	int n , b = 1;
	cin>>n;
	int a[n];
	for(int i = 0; i <n; i++){
		cin >> a[i];
		if(a[i] == 1 && i > 0){
			b++;
			}
	}
	cout << b << endl;
	for(int i = 0; i <n; i++){
		if(a[i] == 1 && i > 0){
			cout <<a[i - 1] << ' ' ;
			}
		}
		cout << a[n - 1];
}