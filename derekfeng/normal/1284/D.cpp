#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void outputno(){
	puts("NO");exit(0);
}
ll mypow(ll x,int t){
	ll res=1,ans=x;
	while (t){
		if (t%2==1){
			res=res*ans%MOD;
			t--;
			continue;
		}
		ans=ans*ans%MOD;t/=2;
	}
}
int n,l[100004][2],r[100004][2],cnt;
map<int,int>mp;
ll d1[200004],d2[200004];
int d3[200004],d4[200004];
int d5[200004],d6[200004];
ll p1[200004],p2[200004];
ll num1[200004],num4[200004];
int num2[200004],num3[200004];
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(l[i][0]),read(r[i][0]),read(l[i][1]),read(r[i][1]),mp[l[i][0]]=mp[r[i][0]]=1;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	for (int i=1;i<=cnt;i++)p1[i]=p2[i]=1;
	for (int i=1;i<=n;i++){
		int v1=mp[l[i][0]],v2=mp[r[i][0]];
		d1[v1]+=i;
		d2[v2]+=i;
		d3[v1]+=__builtin_popcount(i);
		d4[v2]+=__builtin_popcount(i);
		p1[v1]=p1[v1]*i%MOD;
		p2[v2]=p2[v2]*i%MOD;
		d5[v1]++;
		d6[v2]++;
	}
	for (int i=2;i<=cnt;i++) d1[i]+=d1[i-1],d2[i]+=d2[i-1],d3[i]+=d3[i-1],d4[i]+=d4[i-1],d5[i]+=d5[i-1],d6[i]+=d6[i-1];
	for (int i=1;i<=n;i++){
		int v1=mp[l[i][0]],v2=mp[r[i][0]];
		num1[i]=d1[v2]-d2[v1-1];
		num2[i]=d3[v2]-d4[v1-1];
		num3[i]=d5[v2]-d6[v1-1];
		num4[i]=p1[v2]*mypow(p2[v1-1],MOD-2)%MOD;
	}
	mp.clear(),cnt=0;
	for (int i=1;i<=n;i++) mp[l[i][1]]=mp[r[i][1]]=1;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	for (int i=1;i<=cnt;i++)p1[i]=p2[i]=1;
	memset (d1,0,sizeof(d1)),memset (d2,0,sizeof(d2)),memset (d3,0,sizeof(d3)),memset (d4,0,sizeof(d4)),memset (d5,0,sizeof(d5)),memset (d6,0,sizeof(d6));
	for (int i=1;i<=n;i++){
		int v1=mp[l[i][1]],v2=mp[r[i][1]];
		d1[v1]+=i;
		d2[v2]+=i;
		d3[v1]+=__builtin_popcount(i);
		d4[v2]+=__builtin_popcount(i);
		p1[v1]=p1[v1]*i%MOD;
		p2[v2]=p2[v2]*i%MOD;
		d5[v1]++;
		d6[v2]++;
	}
	for (int i=2;i<=cnt;i++) d1[i]+=d1[i-1],d2[i]+=d2[i-1],d3[i]+=d3[i-1],d4[i]+=d4[i-1],d5[i]+=d5[i-1],d6[i]+=d6[i-1];
	for (int i=1;i<=n;i++){
		int v1=mp[l[i][1]],v2=mp[r[i][1]];
		if(num1[i]!=d1[v2]-d2[v1-1]) outputno();
		if(num2[i]!=d3[v2]-d4[v1-1]) outputno();
		if(num3[i]!=d5[v2]-d6[v1-1]) outputno();
		if(num4[i]!=p1[v2]*mypow(p2[v1-1],MOD-2)%MOD) outputno();
	}
	puts("YES");
}