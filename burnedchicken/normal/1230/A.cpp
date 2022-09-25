#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(max(max(max(a,b),c),d)+min(min(min(a,b),c),d)==(a+b+c+d)/2&&(a+b+c+d)%2==0) cout << "YES" << endl;
	else if(max(max(max(a,b),c),d)==(a+b+c+d)/2&&(a+b+c+d)%2==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}