#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	int c = 0;
	while (cin >> x){
		if (!(x & 1))
			cout << "Even" << endl;
		else
			cout << "Odd" << endl;
	}
	return 0;
}