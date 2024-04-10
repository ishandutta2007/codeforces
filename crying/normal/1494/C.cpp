#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,m,a[MAXN],b[MAXN],ans;
int suf[MAXN];
vector<int>v1,v2;
int Solve(vector<int>& a,vector<int>& b){
	int ret=0,n=a.size(),m=b.size();
	// 
	suf[m]=0;
	per(j,m-1,0){
		suf[j]=suf[j+1];
		vit it=lower_bound(a.begin(),a.end(),b[j]);
		if(it!=a.end() && *it==b[j])suf[j]++;
	}
	rep(j,0,m-1){
		int pos=upper_bound(a.begin(),a.end(),b[j])-a.begin();
		if(!pos)continue; //b[j]
		pos; //1~pos
		int L=b[j]-pos+1; //L~b[j]
		int idx=lower_bound(b.begin(),b.end(),L)-b.begin();
		ret=Max(ret,j-idx+1+suf[j+1]);
	}
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		v1.clear();v2.clear();
		ans=0;
		rep(i,1,n){
			cin>>a[i];
			if(a[i]<0)v1.pb(-a[i]);
		}
		rep(i,1,m){
			cin>>b[i];
			if(b[i]<0)v2.pb(-b[i]);
		}
		reverse(v1.begin(),v1.end());
		reverse(v2.begin(),v2.end()); 
		ans+=Solve(v1,v2); 
		v1.clear();v2.clear();
		rep(i,1,n){
			if(a[i]>0)v1.pb(a[i]);
		}
		rep(i,1,m){
			if(b[i]>0)v2.pb(b[i]);
		}
		ans+=Solve(v1,v2);
		printf("%d\n",ans);
	}
	return 0;
}