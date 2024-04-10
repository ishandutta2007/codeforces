#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(a+1==b) cout << a << " " << b << endl;
	else if(a==b) cout << 10*a+1 << " " << 10*a+2 << endl;
	else if(a==9&&b==1) cout << 9 << " " << 10 << endl;
	else cout << -1 << endl;
	return 0;
}