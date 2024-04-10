#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c = 0;
	for (int i = 0; i < 10; i++){
		cout << i << endl;
		string s;
		getline(cin, s);
		if (s == "cool" || s == "not bad" || s == "great!" || s == "don't think so" || s == "don't touch me!") {
			cout << "normal" << endl;;
			return 0;
		}
		else if (s == "terrible" || s == "worse" || s == "don't even" || s == "are you serious?" || s == "go die in a hole" || s == "no way"){
			cout << "grumpy" << endl;;
			return 0;
		}
		else
			c++;
		if (c > 3){
			cout << "normal" << endl;
			return 0;
		}
	}
	cout << "grumpy" << endl;
	return 0;
}