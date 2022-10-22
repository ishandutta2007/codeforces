#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int a[N],b[N];
int a1,a0,b1,b0;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=1;i<=n;i++){
		if(a[i]&1) a1++;
		else a0++;
	}
	for(i=1;i<=m;i++){
		if(b[i]&1) b1++;
		else b0++;
	}
	cout<<min(a0,b1)+min(a1,b0);
	return 0;
}