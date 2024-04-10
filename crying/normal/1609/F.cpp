#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e6+10;
int n;
int b[MAXN],s[80];
int minn[MAXN],maxn[MAXN];
ll a[MAXN],ans;
void Read(ll& num){
	char ch;
	while((ch=getchar()) && !isdigit(ch));num=ch-'0';
	while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
void solve(int l,int r){
	if(l==r){ans++;return;}
	int mid=(l+r)>>1;solve(l,mid);solve(mid+1,r);
	minn[mid]=maxn[mid]=mid;
	minn[mid+1]=maxn[mid+1]=mid+1;
	per(i,mid-1,l){
		minn[i]=minn[i+1];maxn[i]=maxn[i+1];
		if(a[i]<a[minn[i+1]])minn[i]=i;
		if(a[i]>a[maxn[i+1]])maxn[i]=i;
	}
	rep(i,mid+2,r){
		minn[i]=minn[i-1];maxn[i]=maxn[i-1];
		if(a[i]<a[minn[i-1]])minn[i]=i;
		if(a[i]>a[maxn[i-1]])maxn[i]=i;
	}
	int r1=mid,r2=mid;
	per(i,mid,l){
		//lmaxn >= rmaxn , lminn <= rminn
		while(r1<r && a[maxn[r1+1]]<=a[maxn[i]])r1++,s[b[maxn[r1]]]--;
		while(r2<r && a[minn[r2+1]]>=a[minn[i]])r2++,s[b[maxn[r2]]]++;
		if(b[minn[i]]==b[maxn[i]])ans+=min(r1-mid,r2-mid);
		//(r1,r2] -> lmaxn < rmaxn , lminn <= rminn
		if(r1<=r2)ans+=s[b[minn[i]]];
	}
	rep(i,mid+1,r)s[b[maxn[i]]]=0; //clear
	int l1=mid+1,l2=mid+1;
	rep(i,mid+1,r){
		//lmaxn < rmaxn , lminn > rminn
		while(l1>l && a[maxn[l1-1]]<a[maxn[i]])l1--,s[b[maxn[l1]]]--;
		while(l2>l && a[minn[l2-1]]>a[minn[i]])l2--,s[b[maxn[l2]]]++;
		if(b[minn[i]]==b[maxn[i]])ans+=min(mid-l1+1,mid-l2+1);
		//[l2,l1) -> lmaxn > rmaxn , lminn > rminn
		if(l2<l1)ans+=s[b[minn[i]]];
	}
	rep(i,l,mid)s[b[maxn[i]]]=0; //clear
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		Read(a[i]);
		b[i]=__builtin_popcountll(a[i]);
	} 
	solve(1,n);
	printf("%lld",ans);

	return 0;
}