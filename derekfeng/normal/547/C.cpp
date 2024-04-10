#include <bits/stdc++.h>	
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
ll ans,cnt;
int g[66],n,q;
bool vis[200004];
vector<int>v[200004],t[200004];
map<int,ll>mp;
map<int,int>mp1;
void got(int num,int x){
	vector<int>p;
	for (int i=2;i*i<=num;i++) if (num%i==0){
		p.push_back(i);
		while (num%i==0) num/=i;
	}
	if (num>1) p.push_back(num);
	for (int i=1;i<(1<<p.size());i++){
		int mult=1;
		for (int j=0;j<p.size();j++) if (i&(1<<j)) mult*=p[j];
		v[x].push_back(mult);
		mp1[mult]=g[i];
	}
}
void add(int x){
	cnt++;
	for (int i=0;i<v[x].size();i++){
		mp[v[x][i]]++;
		if (mp1[v[x][i]]%2==1) ans+=mp[v[x][i]]-1;
		else ans-=mp[v[x][i]]-1;
	}
}
void reduce(int x){
	cnt--;
	for (int i=0;i<v[x].size();i++){
		mp[v[x][i]]--;
		if (mp1[v[x][i]]%2==1) ans-=mp[v[x][i]];
		else ans+=mp[v[x][i]];
	}
}
ll answers(){
	return cnt*(cnt-1)/2-ans;
}
int main(){
	for (int i=1;i<64;i++) g[i]=__builtin_popcount(i);
	read(n),read(q);
	for (int i=1;i<=n;i++){
		int x;read(x);got(x,i);
	}
	for (int i=1;i<=q;i++){
		int x;read(x);
		if (vis[x]) reduce(x);
		else add(x);
		vis[x]^=1;
		write(answers()),puts("");
	}
}