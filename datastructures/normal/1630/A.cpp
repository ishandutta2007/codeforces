#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,k,ans[100005][2];
int main(){
	ios::sync_with_stdio(false); 
	cin>>t;
	while(t--){
		cin>>n>>k;
		if (n==4){
			if (k==0)cout<<0<<' '<<3<<endl<<1<<' '<<2<<endl;
			if (k==1)cout<<0<<' '<<2<<endl<<1<<' '<<3<<endl;
			if (k==2)cout<<0<<' '<<1<<endl<<2<<' '<<3<<endl;
			if (k==3)cout<<-1<<endl;
		}
		else{
			n--;
			if (k==0){
				for (int i=0;i<=n/2;i++)
					cout<<i<<' '<<(n^i)<<endl;
			}
			else if (k==n){
				cout<<0<<' '<<2<<endl;
				cout<<1<<' '<<k-2<<endl;
				cout<<k<<' '<<k-1<<endl;
				for (int i=3;i<=n/2;i++)
					cout<<i<<' '<<(n^i)<<endl;
			}
			else{
				cout<<0<<' '<<(n^k)<<endl;
				cout<<n<<' '<<k<<endl;
				for (int i=1;i<=n/2;i++)
					if (i!=k&&(n^i)!=k)cout<<i<<' '<<(n^i)<<endl;
			}
		}
	}
	return 0;
}