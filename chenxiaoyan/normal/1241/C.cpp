/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int N=200000;
int n;
int a[N+1];
int b,c,d,e;
int _lcm;
int m;
bool chk(int ans){
	int tot=0,now=0;
	for(int i=_lcm;i<=ans;i+=_lcm)tot+=a[++now]*(b+d);
	for(int i=c;i<=ans;i+=c)if(i%e)tot+=a[++now]*b;
	for(int i=e;i<=ans;i+=e)if(i%c)tot+=a[++now]*d;
//	cout<<ans<<":"<<tot<<"\n";
	return tot>=m;
}
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]/=100;
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	cin>>b>>c>>d>>e>>m;
	if(b<d)swap(b,d),swap(c,e);
	_lcm=c*e/gcd(c,e);
	int ans=n+1;
	for(int i=30;~i;i--)if(ans-(1<<i)>=0&&chk(ans-(1<<i)))ans-=1<<i;
	if(ans==n+1)puts("-1");
	else cout<<ans<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}