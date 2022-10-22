#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ld t, s, q;	cin >> t >> s >> q;
	ld a = 1/ q;
	for (int i = 1; ; i++){
		ld tt = s/ a;
		s += tt * (1 - a);
		if (s >= t){
			cout << i << "\n";
			break;
		}
	}
	return	0;
}