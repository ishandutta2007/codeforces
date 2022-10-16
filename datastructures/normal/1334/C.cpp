#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[600005],b[600005],ans;
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
    ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read(),b[i]=read(),a[i+n]=a[i],b[i+n]=b[i];
	int id=0,mn=1e18;
	for (int i=1;i<=n;i++){
		int lb;
		if (i==1)lb=b[n];
		else lb=b[i-1];
		if (min(a[i],lb)<mn)mn=min(lb,a[i]),id=i;
	}
	for (int i=id;i<id+n;i++){
		if (i==id)ans+=a[i];
		else{
			int lb;
			if (i==1)lb=b[n];
			else lb=b[i-1];
			ans+=max(0ll,a[i]-lb);
		}
	}
	cout<<ans<<endl;
    }
	return 0;
}