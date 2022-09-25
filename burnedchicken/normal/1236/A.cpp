#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;
 
int main(){
	ll t;
	cin >> t;
	ll a,b,c,x,y;
	loop(t){
		cin >> a >> b >> c;
		x=a;
		y=c/2;
		if(b>=2*x+y) cout << 3*(x+y) << endl;
		else if(b>=y){
			x=(b-y)/2;
			cout << 3*(x+y) << endl;
		}
		else cout << 3*b << endl;
	}
	return 0;
}