#include <iostream> 
#include <cstdio>
#define int long long
using namespace std; 
int t,m,d,w;
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin>>t;
	while(t--){
		cin>>m>>d>>w;
		int a=w/(gcd(w,d-1)),b=min(m,d);
		cout<<(b%a+(b-a))*(b/a)/2<<endl;
	}
}