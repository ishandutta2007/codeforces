#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a,b,mx,ans;
inline void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
	return;
}
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
inline int lcm(int a,int b){
	return a*b/gcd(a,b);
}
inline void update(int x){
	int k=x-b;
	if (k<0)return;
	int s=lcm(a+k,b+k);
	if (s<mx)ans=k,mx=s;
	return;
}
signed main(){
	cin>>a>>b;
	if (a==b){
		cout<<0<<endl;
		return 0;
	}
	mx=lcm(a,b);
	if (a<b)swp(a,b);
	for (int i=1;i*i<=a-b;i++){
		if ((a-b)%i==0)update(i),update((a-b)/i);
	}
	int x=a-b;
	x=((b-1)/x+1)*(a-b);
	update(x);
	cout<<ans<<endl;
}