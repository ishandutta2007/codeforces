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
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
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
const int Maxn=100005;
LL a[Maxn];
int n;
LL k;
LL tree[Maxn*4];
void build(int p,int l,int r){
	if (l==r){
		tree[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p]=tree[p*2]*tree[p*2+1];
	tree[p]%=k;
}
LL query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return tree[p];
	}
	int mid=(l+r)>>1;
	LL ans=1;
	if (lo<=mid){
		ans*=query(p*2,l,mid,lo,min(hi,mid));
	}
	if (hi>mid){
		ans*=query(p*2+1,mid+1,r,max(lo,mid+1),hi);
		ans%=k;
	}
	return ans;
}
int main(){
	scanf("%d %I64d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a[i]%=k;
	}
	build(1,1,n);
	LL res=0;
	for (int l=1;l<=n;l++){
		int lf=l,rg=n;
		while (rg-lf>1){
			int md=(lf+rg)>>1;
			if (query(1,1,n,l,md)==0){
				rg=md;
			}
			else{
				lf=md;
			}
		}
		if (query(1,1,n,l,lf)==0){
			res+=(LL)(n-lf+1);
		//	cout<<lf<<endl;
		} 
		else if (query(1,1,n,l,rg)==0){
			res+=(LL)(n-rg+1);
		//	cout<<rg<<endl;
		}
	}
	printf("%I64d\n",res);
	return 0;
}