//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
LL vval[Maxn];
int n,q;
/*
void modify(int p,int l,int r,int pos,long long val){
	if (l==r){
		vval[pos]=max(vval[pos],val);
		tree[p]=max(tree[p],val);
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos,val);
	}
	else{
		modify(p*2+1,mid+1,r,pos,val);
	}
	tree[p]=max(tree[p*2],tree[p*2+1]);
}
long long query(int p,int l,int r,int lo,int hi){
	if (lo>hi) return -1e18;
	if (lo<=l && r<=hi){
		return tree[p];
	}
	int mid=(l+r)>>1;
	long long ans=-1e18;
	if (lo<=mid){
		ans=max(ans,query(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=max(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}*/
long long v[Maxn];
int c[Maxn];
long long dp[Maxn];
map<int,int> ex;
int main(){

	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&v[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%I64d",&c[i]);
	}
	while (q--){
		//if (flag && q<=300) throw 3;
		for (int i=0;i<Maxn;i++) vval[i]=-1e18; 
		for (int i=0;i<=n;i++) dp[i]=0LL;
		long long a,b;
		scanf("%I64d %I64d",&a,&b);
		long long ans=0;
		long long Mx1=0,Mx2=0;
		int Mx1i=-1,Mx2i=-1;
		for (int i=1;i<=n;i++){
			LL M1,M2;
			if (c[i]!=Mx1i){
				M1=Mx1;
			}
			else{
				M1=Mx2;
			}
			//cout<<M1<<endl;
			M1+=b*v[i];
			LL M3=vval[c[i]]+a*v[i];
			//cout<<vval[c[i]]<<endl;
			dp[i]=max(M1,M3);
			bool flag=false;
			if (dp[i]>vval[c[i]]) vval[c[i]]=max(vval[c[i]],dp[i]),flag=true;
			
			ans=max(ans,dp[i]);
			if (flag){
				if (vval[c[i]]>Mx1){
					if (c[i]!=Mx1i){
						Mx2=Mx1;
						Mx2i=Mx1i;
						Mx1=vval[c[i]];
						Mx1i=c[i];
					}
					else{
						Mx1=vval[c[i]];
						Mx1i=c[i];
					}
				}
				else if (vval[c[i]]>Mx2){
					Mx2=vval[c[i]];
					Mx2i=c[i];
				}
			}
			
			//cout<<dp[i]<<endl;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}