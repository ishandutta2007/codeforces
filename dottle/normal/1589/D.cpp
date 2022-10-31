#include<bits/stdc++.h>
#define int long long
const int N=105000;
using namespace std;

int calc(int k){
	int x=sqrt(2*k);
	for(int i=max(2ll,x-5);i<=x+5;i++)
		if(i*(i-1)/2==k)return i;
	return -1;
}

void solve(){
	int n;cin>>n;
	int l=1,r=n,ans=n,all,lst=0;
	cout<<"? 1 "<<n<<endl;cin>>all;
	while(l<=r){
		int mid=(l+r)>>1;
		cout<<"? "<<1<<' '<<mid<<endl;
		int x;cin>>x;
		if(x==0)ans=mid,l=mid+1;
		else r=mid-1;
	}
	int I=ans,J,K;
	int A,B,C;
	cout<<"? "<<I<<' '<<I+1<<endl;
	cout<<"? "<<I+2<<' '<<n<<endl;
	cin>>A>>B;
	int t=all-A-B;
	J=I+2+t/2;
	cout<<"? "<<I<<' '<<J-1<<endl;
	cin>>C;
	K=J+calc(all-C)-1;
	cout<<"! "<<I<<' '<<J<<' '<<K<<endl;
}

main(){
	int t;cin>>t;while(t--)solve();
}