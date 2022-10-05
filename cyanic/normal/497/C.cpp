#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
struct node{
	int l,r,id,k;
	friend bool operator < (node x,node y){
		return x.r<y.r;
	}
} a[N],b[N];
int ans[N],n,m,x,y,z,p=1;
set<pii> s;

int main(){
	read(n);
	rep(i,1,n){
		read(x),read(y);
		a[i]=(node){x,y,i,0};
	}
	read(m);
	rep(i,1,m){
		read(x),read(y),read(z);
		b[i]=(node){x,y,i,z};
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	rep(i,1,m){
		while(p<=n&&a[p].r<=b[i].r){
			s.insert(mp(a[p].l,a[p].id));
			p++;
		}
		for(;b[i].k;b[i].k--){
			set<pii>::iterator it;
			it=s.lower_bound(mp(b[i].l,0));
			if(it==s.end()) break;
			ans[it->se]=b[i].id;
			s.erase(it);
		}
	}
	if(p<=n||!s.empty()){
		puts("NO");
		return 0;
	}
	puts("YES");
	rep(i,1,n){
		printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}