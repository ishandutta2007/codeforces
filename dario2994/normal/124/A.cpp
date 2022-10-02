#include <iostream>
using namespace std;
int main(){
	int n;
	int a,b;
	cin >> n >> a >> b;
	cout << min(b+1,n-a);
}