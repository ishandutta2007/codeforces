#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;
 
int main(){
	ll n,p,w,d,q,a,b;
	cin >> n >> p >> w >> d;
	q=p%w;
	loop(w){
		if((d*i-q)%w==0){
			b=i;
			break;
		}
		if(i==w-1){
			cout << -1 << endl;
			return 0;
		}
	}
	a=(p-d*b)/w;
	if(a<0){
		cout << -1 << endl;
		return 0;
	}
	if((a+b)>n){
		cout << -1 << endl;
		return 0;
	}
	cout << a << " " << b << " " << n-a-b << endl;
	return 0;
}