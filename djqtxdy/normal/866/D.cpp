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
#include <assert.h>
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
// atcoder IO: ????
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=300005;
int tree[Maxn*4];
int id[Maxn*4]; 
void modify(int p,int l,int r,int pos,int val){
//	cout<<pos<<endl; 
	if (l==r){
		tree[p]=val;
		id[p]=l;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos,val);
	}
	else{
		modify(p*2+1,mid+1,r,pos,val);
	}
	tree[p]=min(tree[p*2],tree[p*2+1]);
	pair<int,int> fuck=min(mp(tree[p*2],-id[p*2]),mp(tree[p*2+1],-id[p*2+1]));
	id[p]=-fuck.second;
}
pair<int,int> query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return mp(tree[p],-id[p]);
	}
	int mid=(l+r)>>1;
	pair<int,int> ans={1e9,-1};
	if (hi<lo) return ans;
	if (lo<=mid){
		ans=min(ans,query(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=min(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi)); 
	}
	return ans;
}
vector<pair<int,int> > p;
int a[Maxn];
bool cmp(pair<int,int> a,pair<int,int> b){
	if (a.first!=b.first) return a.first>b.first;
	return a.second<b.second;
}
priority_queue<int> q;
int main(){
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (!q.empty()){
			int x=-q.top();
			if (x<a[i]){
				q.pop();
				ans+=a[i]-x;
				q.push(-a[i]);
			}
			
		}
		q.push(-a[i]);
	}
	printf("%I64d\n",ans);
	return 0;
	sort(p.begin(),p.end(),cmp);
	//long long ans=0;
	for (int i=0;i<p.size();i++){
		int pos=p[i].second,val=p[i].first;
		//cout<<pos<<val<<endl; 
		if (query(1,1,n,pos,pos).first==1e9) continue;
		modify(1,1,n,pos,1e9);
		pii kk=query(1,1,n,1,pos-1);
		if (kk.first>=val) continue;
		ans+=val-kk.first;
		modify(1,1,n,-kk.second,1e9);
		
		//cout<<val<<' '<<kk.first<<kk.second<<endl;
	}
	printf("%I64d\n",ans);
	return 0;
}