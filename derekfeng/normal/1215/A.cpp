#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,n;cin>>a>>b>>c>>d>>n;
	if (c<d) swap(c,d),swap(a,b);
	cout<<max(0,n-(c-1)*a-(d-1)*b)<<" "; 
	if (d*b>=n){
		cout<<n/d;return 0;
	}
	cout<<(n-d*b)/c+b;
}