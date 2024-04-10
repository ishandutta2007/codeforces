#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[200005],mx,mg,y,z;
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]),mx=max(mx,a[i]);
	mg=mx-a[1];
	for (int i=1;i<=n;i++){
		if (mx-a[i]==0)continue;
		if (mx-a[i]!=0){
			if (mg==0)mg=mx-a[i];
			else mg=gcd(mg,mx-a[i]);
		}
	}
	if (mg==0){
		cout<<0<<' '<<0<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)y+=(mx-a[i])/mg;
	cout<<y<<' '<<mg<<endl;
	return 0;
}