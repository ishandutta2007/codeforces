#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=1000000007;
int n,m;
bool a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	if(m==1){
		cout<<0;
		for(i=2;i<=n;i++) cout<<1;
		return 0;
	}
	int k=(n-m)/2+1;
	for(i=1;i<=n;i+=k)
		a[i]=1;
	for(i=1;i<=n;i++) cout<<a[i];
	return 0;
}