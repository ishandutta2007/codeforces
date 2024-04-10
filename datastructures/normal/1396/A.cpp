#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[100005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if (n==1){
		cout<<1<<' '<<1<<endl;
		cout<<-a[1]<<endl;
		cout<<1<<' '<<1<<endl;
		cout<<0<<endl;
		cout<<1<<' '<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<' '<<n-1<<endl;
	for (int i=1;i<=n-1;i++){
		int qwq=a[i];
		qwq%=n;
		int d=qwq*(n-1);
		printf("%lld ",d);
		a[i]+=d;
	}
	puts("");
	cout<<2<<' '<<n<<endl;
	for (int i=2;i<=n;i++){
		int qwq=a[i];
		qwq%=n;
		int d=qwq*(n-1);
		printf("%lld ",d);
		a[i]+=d;
	}
	puts("");
	cout<<1<<' '<<n<<endl;
	for (int i=1;i<=n;i++)printf("%lld ",-a[i]);
	puts("");
	return 0;
}