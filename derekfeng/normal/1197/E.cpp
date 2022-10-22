#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int MOD=1e9+7; 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,ans;
pii paryi[200004];
int ena[200004],mana[200004];
int dist[200004],cnt[200004],D=1e9+1;
void add(int &a,int &b,int c,int d){
	if (a<c) return;
	if (a>c) a=c,b=0;
	b+=d;
	if (b>=MOD) b-=MOD; 
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(paryi[i].se),read(paryi[i].fi);
	sort (paryi+1,paryi+1+n);
	for (int i=1;i<=n;i++) ena[i]=paryi[i].fi,mana[i]=paryi[i].se,dist[i]=1e9;
	cnt[0]=1; 
	for (int i=1;i<=n;i++){
		add(dist[i],cnt[i],dist[i-1]+ena[i]-ena[i-1],cnt[i-1]);
		int num=lower_bound(ena+1,ena+1+n,mana[i])-ena;
		if (num>n) continue;
		add(dist[num],cnt[num],dist[i]+ena[num]-mana[i],cnt[i]);
	}
	for (int i=1;i<=n;i++) if (mana[i]>ena[n]) add(D,ans,dist[i],cnt[i]);
	write(ans);
}