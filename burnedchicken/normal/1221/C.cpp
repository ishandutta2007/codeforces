#include <iostream>
#include <cmath>

using namespace std;
int main(){
	int q;
	cin >> q;
	int c,m,x,t;
	for(int i=0; i<q; i++){
		t=0;
		cin >> c >> m >> x;
		t=min(min(c,m),x);
		c=c-t;
		m=m-t;
		x=x-t;
		if(c*m==0) cout << t << endl;
		else if(c>=m*2) cout << t+m << endl;
		else if(m>=c*2) cout << t+c << endl;
		else cout << t+(m+c)/3 << endl;
	}
	return 0;
}