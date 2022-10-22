#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
int a,b,n;
ll ans,cnt[1000004],inv[1000004];
void init(){
	cnt[0]=1,inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[0]=1;
	for (int i=1;i<=n;i++)cnt[i]=cnt[i-1]*i%MOD,inv[i]=inv[i-1]*inv[i]%MOD;
}
ll C(int x,int y){
	return cnt[y]*inv[x]%MOD*inv[y-x]%MOD;
}
bool ok(int x){
	bool res=1;
	if (x>9) res&=ok(x/10);
	if (x%10!=a && x%10!=b) res=0;
	return res;
}
int main(){
	read(a),read(b),read(n),init();
	for (int i=a*n;i<=b*n;i++){
		if ((i-a*n)%(b-a)) continue;
		if (!ok(i)) continue;
		int y=(i-a*n)/(b-a);
		ans=(ans+C(y,n))%MOD;
	}
	write(ans);
}