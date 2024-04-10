#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int t;
	cin >> t;
	ll a,b;
	loop(t){
		cin >> a >> b;
		if(a-b==1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}