#include<iostream>
#include<algorithm>

using namespace std;
bool ok[108000];
int main(){
	int n, t, a;
	cin >> n >> t;
	ok[1] = true;
	for(int i = 1;i <= n - 1;i++){
		cin >> a;
		ok[a + i] |= ok[i];
	}
	
	cout << (ok[t]?"YES":"NO") << endl;
	return 0;
}