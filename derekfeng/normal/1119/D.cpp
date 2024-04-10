#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void readi(ll &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const ll M=1e18;
int n,q;
ll s[100004];
ll d[100004];
vector<ll>v;
int main(){
	read(n);
	for (int i=1;i<=n;i++) readi(s[i]);
	sort (s+1,s+1+n);
	for (int i=1;i<=n-1;i++) v.push_back(s[i+1]-s[i]);
	sort (v.begin(),v.end());
	for (int i=0;i<v.size();i++) d[i+1]=d[i]+v[i];
	read(q);
	while (q--){
		ll l,r;readi(l),readi(r);
		int ld=upper_bound(v.begin(),v.end(),r-l+1)-v.begin();
		write((n-ld)*(r-l+1)+d[ld]);putchar(' ');
	}
}