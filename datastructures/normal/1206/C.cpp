#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int n,a[1000005],book[2000005],s;
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>n;
	n=2*n;
	if (n*(n+1)/2%2==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	int sum[2]={n*(n+1)/4,n*(n+1)/4+1};
	int now=n,nowsum=sum[1],tot=0;
	while(tot<n/2){
		while(book[now]||book[now+1-2*((tot+1)%2)]&&now>0)now--;
		if (now==0){
			cout<<"NO"<<endl;
			return 0;
		}
		a[++tot]=now;
		a[tot+n/2]=now+1-2*(tot%2);
		book[a[tot]]=book[a[tot+n/2]]=1;
	}
	for (int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}