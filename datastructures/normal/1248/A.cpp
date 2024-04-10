#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int a1,a2,b1,b2,x,t,n,m;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		a1=a2=b1=b2=0;
		for (int i=1;i<=n;i++){
			scanf("%I64d",&x);
			if (x%2)a1++;
			else a2++;
		}
		cin>>m;
		for (int i=1;i<=m;i++){
			scanf("%I64d",&x);
			if (x%2)b1++;
			else b2++;
		}
		cout<<(a1*b1+a2*b2)<<endl;
	}
	return 0;
}