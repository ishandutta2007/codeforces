#include<bits/stdc++.h>
using namespace std;

int s=0,x,a[10000];

bool chk(int k){
	for(int i=2;i*i<=k;i++)
		if(k%i==0)
			return 1;
	return 0;
}

void solve(){
	int n;
	cin>>n;s=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	if(chk(s)){
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			cout<<i<<' ';
		cout<<endl;
		return ;
	}
	cout<<n-1<<endl;
	for(int i=1;i<=n;i++)
		if(a[i]&1){
			for(int j=1;j<=n;j++)
				if(i!=j)
					cout<<j<<' ';
			cout<<endl;
			return ;
		}
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}