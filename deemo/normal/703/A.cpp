#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;	cin >> n;
	int aa = 0, bb = 0;
	while (n--){
		int a, b;	cin >> a >> b;
		if (a > b)	aa++;
		if (b > a)	bb++;
	}
	if (aa > bb)
		cout << "Mishka\n";
	else if (bb > aa)
		cout << "Chris\n";
	else
		cout << "Friendship is magic!^^\n";
	return 0;
}