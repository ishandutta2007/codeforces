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
const int MAXN=13,MAXM=2e5+10;
int n,m,c[MAXN],a[MAXN][MAXM];
set<vector<int> >invalid;
vector<int>lim;
struct Node{
	vector<int>tag;
	int sum;
	bool operator<(const Node& n2)const{
		if(sum!=n2.sum)return sum<n2.sum;
		rep(i,0,n-1)if(tag[i]!=n2.tag[i])return tag[i]<n2.tag[i];
		return 0;
	}
}f;
priority_queue<Node>h;
set<Node>pc;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&c[i]);
		rep(j,1,c[i]){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&m);
	rep(i,1,m){
		lim.clear();
		rep(j,1,n){
			int val;scanf("%d",&val);
			lim.pb(val);
		}
		invalid.is(lim);
	}
	rep(i,1,n){
		f.tag.pb(c[i]);
		f.sum+=a[i][c[i]];
	}
	h.push(f);pc.is(f);
	while(h.size()){
		Node now=h.top();h.pop();
		if(invalid.find(now.tag)==invalid.end()){
			for(auto v:now.tag){
				printf("%d ",v);
			} 
			return 0;
		}
		//
		rep(i,1,n){
			if(now.tag[i-1]==1)continue;
			int idx=now.tag[i-1];
			Node tmp=now;
			tmp.tag[i-1]--;
			tmp.sum-=(a[i][idx]-a[i][idx-1]);
			if(pc.find(tmp)==pc.end()){
				h.push(tmp);
				pc.is(tmp); 
			}
		}	 

	}
	return 0;
}