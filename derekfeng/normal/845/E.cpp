#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void readsh(short &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
short k;
int n,m,datx[503],daty[503],t1,t2,min1,max1,min2,max2;
vector<pii>g[1003],f[1003];
map <int,short> vis1,vis2,mp1,mp2;
int upd[1003],lfd[1003];
int num[1003],add[1003];
short check(int x){
	min1=2e9,max1=0,min2=2e9,max2=0;
	for (int i=1;i<1003;i++) num[i]=0,g[i].clear(),f[i].clear();
	vis1.clear(),vis2.clear();t1=0,t2=0;
	for (int i=1;i<=k;i++){
		int a=max(1,daty[i]-x),b=min(m,daty[i]+x);
		int c=max(1,datx[i]-x),d=min(n,datx[i]+x);
		if (!vis1[a]) vis1[a]=1;if (!vis1[b+1]) vis1[b+1]=1;
		if (!vis2[c]) vis2[c]=1;if (!vis2[d+1]) vis2[d+1]=1;
	}
	vis1[1]=1,vis2[1]=1;
	vis1[m+1]=1,vis2[n+1]=1;
	for (map<int,short>::iterator it=vis1.begin();it!=vis1.end();it++) upd[++t1]=it->first,mp1[it->first]=t1;
	for (map<int,short>::iterator it=vis2.begin();it!=vis2.end();it++) lfd[++t2]=it->first,mp2[it->first]=t2;
	for (int i=1;i<=k;i++){
		int a=max(1,daty[i]-x),b=min(m,daty[i]+x);
		int c=max(1,datx[i]-x),d=min(n,datx[i]+x);
		g[mp1[a]].push_back(mkp(mp2[c],mp2[d+1])),f[mp1[b+1]].push_back(mkp(mp2[c],mp2[d+1]));
	}
	for (int i=1;i<t1;i++){
		memset (add,0,sizeof(add));
		for (int j=0;j<g[i].size();j++) add[g[i][j].fi]++,add[g[i][j].se]--;
		for (int j=0;j<f[i].size();j++) add[f[i][j].fi]--,add[f[i][j].se]++;
		for (int j=1;j<t2;j++) add[j]+=add[j-1];
		for (int j=1;j<t2;j++) num[j]+=add[j];
		for (int j=1;j<t2;j++) if (num[j]==0)
			min1=min(min1,upd[i]),max1=upd[i+1]-1,min2=min(min2,lfd[j]),max2=max(max2,lfd[j+1]-1);
	} 
	return (max1-min1<=2*x)&&(max2-min2<=2*x);
}
int main(){
	read(n),read(m),readsh(k);
	for (int i=1;i<=k;i++) read(datx[i]),read(daty[i]);
	int l=-1,r=2e9+1;
	while (r>l+1){
		int mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	write(r);
}