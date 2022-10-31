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
int tree[Maxn*100];
int l[Maxn*100],r[Maxn*100];
vector<int> v[Maxn];
int a[Maxn];
int root[Maxn];
int siz=1;
int nowroot;
int modify(int p,int lo,int hi,int pos,int val){
	int newnode=siz++;
	l[newnode]=l[p];
	r[newnode]=r[p];
	if (lo==hi){
		tree[newnode]=val;
		return newnode;
	}
	int mid=(lo+hi)>>1;
	if (pos<=mid){
		l[newnode]=modify(l[p],lo,mid,pos,val);
	}
	else{
		r[newnode]=modify(r[p],mid+1,hi,pos,val);
	}
	tree[newnode]=tree[l[newnode]]+tree[r[newnode]];
	return newnode;
}
int query(int p,int lo,int hi,int llo,int hhi){
	if (llo<=lo && hi<=hhi){
		return tree[p];
	}
	int mid=(lo+hi)>>1;
	int ans=0;
	if (llo<=mid){
		ans+=query(l[p],lo,mid,llo,min(hhi,mid));
	}
	if (hhi>mid){
		ans+=query(r[p],mid+1,hi,max(llo,mid+1),hhi);
	}
	return ans;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		int Size=v[a[i]].size();
		if (Size>k){
			int lf=v[a[i]][Size-k-1];
			//cout<<lf<<endl;
			nowroot=modify(nowroot,1,n,lf,0);
			//lf->i
			
		}
		root[i]=modify(nowroot,1,n,i,1);
		nowroot=root[i];
	} 
	int q;
	scanf("%d",&q);
	int last=0;
	while (q--){
		int lo,hi;
		scanf("%d %d",&lo,&hi);
		lo+=last,hi+=last;
		lo%=n,hi%=n;
		lo++,hi++;
		if (lo>hi) swap(lo,hi);
	//	cout<<"query:"<<lo<<' '<<hi<<endl;
		last=query(root[hi],1,n,lo,hi);
		printf("%d\n",last);
	} 
	return 0;
}