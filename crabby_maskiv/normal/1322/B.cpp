#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
const int inf=0x3f3f3f3f;
int n,m,k;
int a[N];
int b[N];
int ans=0;
void solve(int x){
	int i,j,p=n+1;
	for(i=1;i<=n;i++) b[i]=a[i]-((a[i]>>(x+1))<<(x+1));
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		if(b[i]>=(1<<x)){
			p=i;
			break;
		}
	}
	for(i=p;i<=n;i++) b[i]-=(1<<x);
	int pos=p;
	bool f=0;
	for(i=1;i<p;i++){
		while(pos>1&&b[i]+b[pos-1]>=(1<<x)) pos--;
		if(pos<=i) f^=((p-i-1)&1);
		else f^=((p-pos)&1);
	}
	pos=n+1;
	for(i=p;i<=n;i++){
		while(pos>p&&b[i]+b[pos-1]>=(1<<x)) pos--;
		if(pos<=i) f^=((n-i)&1);
		else f^=((n+1-pos)&1);
	}
	pos=p;
	for(i=p-1;i;i--){
		while(pos<=n&&b[i]+b[pos]<(1<<x)) pos++;
		f^=((pos-p)&1);
	}
	ans+=f*(1<<x);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<25;i++)
		solve(i);
	cout<<ans;
	return 0;
}