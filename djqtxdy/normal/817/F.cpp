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
#define pii pair<long long,long long>
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
const int Maxn=712345;
const int Maxt=2812345;
int tree[Maxt],tag[Maxt];
map<long long,int> to;
long long from[Maxn];
vector<piii > qu;
void Push(int p,int l,int r){
	tag[p*2]^=tag[p];
	tag[p*2+1]^=tag[p];
	int mid=(r+l)>>1;
	if (tag[p]){
		tag[p]=false;
		tree[p]=(r-l+1)-tree[p];
	}
	if (tree[p]==(r-l+1)){
		tag[p*2]=tag[p*2+1]=false;
		tree[p*2]=(mid-l+1);
		tree[p*2+1]=tree[p]-tree[p*2];
		//cout<<"act"<<endl;
	}
	if (tree[p]==0){
		tag[p*2]=tag[p*2+1]=false;
		tree[p*2]=0;
		tree[p*2+1]=0;
	}
	
}
int G(int p,int l,int r){
	if (tag[p]) return (r-l+1)-tree[p];
	else return tree[p];
}
void modify(int p,int l,int r,int lo,int hi,int val){
	if (lo<=l && r<=hi){
		//cout<<"modify:"<<l<<' '<<r<<endl;
		if (tag[p]) tree[p]=(1-val)*(r-l+1);
		else tree[p]=val*(r-l+1);
		return;
	}
	Push(p,l,r);
	int mid=(l+r)>>1;
	if (lo<=mid){
		modify(p*2,l,mid,lo,min(hi,mid),val);
	}
	if (hi>mid){
		modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
	int ans=G(p*2,l,mid)+G(p*2+1,mid+1,r);
	if (tag[p]){
		ans=(r-l+1)-ans;
	}
	tree[p]=ans;
//	if (l==3 && r==4) cout<<tag[p]<<' '<<tree[p]<<endl;
}
void rev(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
	//	cout<<"modify:"<<l<<' '<<r<<endl;
		tag[p]^=1;
		return;
	}
	
	int mid=(l+r)>>1;
	Push(p,l,r);
	if (lo<=mid){
		rev(p*2,l,mid,lo,min(hi,mid));
	}
	if (hi>mid){
		rev(p*2+1,mid+1,r,max(lo,mid+1),hi);
	}
	
	int ans=G(p*2,l,mid)+G(p*2+1,mid+1,r);
	if (tag[p]){
		ans=(r-l+1)-ans;
	}
	tree[p]=ans;
//	cout<<l<<' '<<r<<' '<<tree[p]<<' '<<tag[p]<<endl;
}
int Get(int p,int l,int r){
	int nv=tree[p];
	
	if (tag[p]){
		nv=(r-l+1)-nv;
	}
//	cout<<l<<' '<<r<<' '<<nv<<endl;
	
	if (nv==(r-l+1)){
		return -1;
	}
	if (nv==0){
		return l-1;
	}
	if (l==r) return l-1;
	Push(p,l,r);
	int mid=(l+r)>>1;
	int val=Get(p*2,l,mid);
	if (val!=-1){
		return val;
	}
	else{
		return Get(p*2+1,mid+1,r);
	}
}
int main(){
	int q;
	scanf("%d",&q);
	while (q--){
		int tp;
		scanf("%d",&tp);
		long long l,r;
		scanf("%I64d %I64d",&l,&r);
		to[l]=0,to[r]=0;
		to[l-1]=0,to[r+1]=0;
		to[l+1]=0,to[r-1]=0;
		qu.push_back(mp(tp,mp(l,r)));
	}
	int cnt=0;
	for (map<long long,int> ::iterator it=to.begin();it!=to.end();it++){
		if (it->first==0LL) continue;
		it->second=++cnt;
		from[cnt]=it->first;
		//printf("%d : %I64d\n",cnt,it->first);
	}
	for (int i=0;i<qu.size();i++){
		int tp;
		long long l,r;
		tp=qu[i].first,l=qu[i].second.first,r=qu[i].second.second;
		int L=to[l],R=to[r];
		if (tp==1){
			modify(1,1,cnt,L,R,1);
		} 
		else if (tp==2){
			modify(1,1,cnt,L,R,0);
		}
		else{
			rev(1,1,cnt,L,R);
		}
		int ans=Get(1,1,cnt);
		long long res=from[ans]+1;
		printf("%I64d\n",res);
	}
} 
/*
1
1 10 15
*/