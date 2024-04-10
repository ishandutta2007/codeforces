#include<bits/stdc++.h>
const int N=1050050;
using namespace std;



int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),p(105); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=0;
		while(a[i])p[cnt]+=a[i]&1,a[i]>>=1,cnt++;
	}
	int gc=0;
	for(int i=0;i<100;i++)
		gc=gcd(gc,p[i]);
	for(int i=1;i<=n;i++)
		if(gc%i==0)
			cout<<i<<' ';
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--)solve();
}