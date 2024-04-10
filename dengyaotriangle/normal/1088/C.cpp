#include<bits/stdc++.h>

using namespace std;

const int maxn=2005;

int n;
int a[maxn];
int mxn;
int opt[maxn];
int pfx[maxn];
int btc;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mxn=n+100;
	for(int i=1;i<=n;i++){
		 opt[i]=((i-(a[i]%mxn))%mxn+mxn)%mxn;
	}
	cout<<n+1<<endl;
	cout<<"1 "<<n<<' '<<opt[n]<<endl;
	btc=opt[n];
	for(int i=n-1;i>=1;i--){
		int ex=opt[i]-btc;
		ex=(ex%mxn+mxn)%mxn;
		cout<<"1 "<<i<<' '<<ex<<endl;
		btc+=ex;
	}
	cout<<"2 "<<n<<' '<<mxn;
	return 0;
}