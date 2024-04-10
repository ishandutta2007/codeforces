#include<bits/stdc++.h>
const int N=100005; 
using namespace std;

int n,a[N];

void solve(){
	cin>>n,n<<=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)
		cout<<a[i]<<' '<<a[n-i+1]<<' ';
	cout<<endl;
} 

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)solve();
	
}