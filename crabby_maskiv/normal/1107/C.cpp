#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
ll b[N];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>b[i];
	cin>>(a+1);
	ll sum=0;
	for(i=1;i<=n;){
		for(j=i;j<=n;j++)
			if(a[i]!=a[j]) break;
		sort(b+i,b+j,cmp);
		i=j;
	}
	for(i=1;i<=n;){
		for(j=i;j<=n;j++){
			if(a[i]!=a[j]) break;
			if(j-i+1<=m) sum+=b[j];
		}
		i=j;
	}
	cout<<sum;
	return 0;
}