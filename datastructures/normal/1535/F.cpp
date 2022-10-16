#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
#define mod 9999999967
#define base1 91
#define base2 19260817
using namespace std;
int n,m;
string s[200005];
vector <int>pre[200005],suf[200005],hs2[200005],c[200005];
int pw2[200005];
struct node{
	int l,r;
}d[200005];
int len;
inline bool cmp(node a,node b){
	if (a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
struct Hash{
	int v1,v2,v3;
	bool operator <(const Hash &x)const{
		if (v1!=x.v1)return v1<x.v1;
		if (v2!=x.v2)return v2<x.v2;
		return v3<x.v3;
	}
};
map <int,int>w1,w2;
map <Hash,int>w3;
int num0,num1,num2,num3;
inline Hash Make_Hash(register int i,register int l,register int r){
	register int v1=0,v2=0,v3=0;
	if (l>0)v1=pre[i][l-1];
	if (l==0)v2=hs2[i][r];
	else v2=(hs2[i][r]-hs2[i][l-1]+mod)%mod;
	if (r+1<m)v3=suf[i][r+1];
	register Hash ans;
	ans.v1=v1,ans.v2=v2,ans.v3=v3;
	return ans;
}
inline bool ok(register int i,register int l,register int r){
	return c[i][r]!=c[i][l];
}
signed main(){
	cin>>n;
	pw2[0]=1;
	for (register int i=1;i<=26;i++)pw2[i]=1ll*pw2[i-1]*base2%mod;
	for (register int i=1;i<=n;i++){
		string t;
		cin>>t;
		s[i]=t;
		m=t.size();
		register int nowpre=0,nowsuf=0,now2=0,nowc=0;
		for (register int j=0;j<m;j++){
			nowpre=(1ll*nowpre*base1%mod+t[j]-'a'+1)%mod;
			now2=(now2+1ll*pw2[t[j]-'a'+1]%mod)%mod;
			if (j>0&&t[j]<t[j-1])nowc++; 
			pre[i].push_back(nowpre),suf[i].push_back(nowsuf),hs2[i].push_back(now2),c[i].push_back(nowc);
		}
		for (register int j=m-1;j>=0;j--){
			nowsuf=(1ll*nowsuf*base1%mod+t[j]-'a'+1)%mod;
			suf[i][j]=nowsuf;
		}
		for (register int j=0;j<m;j++){
			register int k=j;
			while((k+1)<m&&t[k+1]>=t[k])k++;
			++len;
			d[len].l=j,d[len].r=k;
			w3[Make_Hash(i,j,k)]++;
			j=k;
		}
		num0+=w1[pre[i][m-1]],w1[pre[i][m-1]]++;
		num3+=i-1-w2[hs2[i][m-1]],w2[hs2[i][m-1]]++;
	}
	sort(d+1,d+1+len,cmp);
	register int _len=len;
	len=0;
	for (register int i=1;i<=_len;i++)
		if (i==1||d[i].l!=d[i-1].l||d[i].r!=d[i-1].r)d[++len]=d[i];
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=len;j++)
			if (ok(i,d[j].l,d[j].r))num1+=w3[Make_Hash(i,d[j].l,d[j].r)];
	num2=1ll*n*(n-1)/2-num0-num1-num3;
	cout<<(num1+2*num2+1337*num3)<<endl;
	return 0;
}