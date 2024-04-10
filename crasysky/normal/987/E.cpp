#include <iostream>
using namespace std;
int a[1000006], c[1000006];
int ask(int x){
	int ans = 0;
	for (; x; x -= x & -x)
		ans += c[x];
	return ans;
}
void add(int x){
	for (; x <= 1000000; x += x & -x)
		c[x] ++;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	int cnt = 0;
	for (int i = n; i; -- i){
		cnt ^= ask(a[i]);
		add(a[i]);
	}
	if (((cnt & 1) ^ (n & 1)) == 0)
		cout << "Petr" << endl;
	else
		cout << "Um_nik" << endl;
}