#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int t;
	double a,b,c,d,k;
	cin >> t;
	loop(t){
		cin >> a >> b >> c >> d >> k;
		if(ceil(a/c)+ceil(b/d)>k) cout << -1 << endl;
		else cout << ceil(a/c) << " " << ceil(b/d) << endl;
	}
	return 0;
}