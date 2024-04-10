#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
int n,m;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		if(a[1]<a[n]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}