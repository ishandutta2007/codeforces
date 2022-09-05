#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1266666;
set<Pii>Set;int n,b[N];ll s;
int ans1[N*2],ans2[N*2],ans3[N*2],sz;
void move(int i, int j, int d){
	if(i==j)return;
	sz++;ans1[sz]=i;ans2[sz]=j;ans3[sz]=d;
}
int main() {
	read(n);
	rep(i,1,n){int x;read(x);Set.insert(Pii(x,i));s+=x;}
	rep(i,1,n)read(b[i]),s-=b[i];
	sort(b+1,b+n+1);
	if(s){puts("NO");return 0;}
	if(b[1]<(*Set.begin()).fi||b[n]>(*Set.rbegin()).fi){puts("NO");return 0;}
	int l=1,r=n;
	while(SZ(Set)){
		int x=(*Set.begin()).fi;
		if(x==b[l]){
			Set.erase(Set.begin());l++;continue;
		}
		if(x>b[l]){puts("NO");return 0;}
		set<Pii>::iterator it=Set.lower_bound(Pii(b[l],-1)),it1=it;
		it1--;
		int d=min((*it).fi-b[l],b[l]-(*it1).fi);
		move((*it1).se,(*it).se,d);
		if((*it).fi-d==b[l]){
			Set.erase(it);
			Pii tmp=*it1;tmp.fi+=d;
			Set.erase(it1);Set.insert(tmp);
		}
		else{
			Set.erase(it1);
			Pii tmp=*it;tmp.fi-=d;
			Set.erase(it);Set.insert(tmp);
		}
		l++;
	}
	/*while(SZ(Set)){
		int x=(*Set.begin()).fi,y=(*Set.rbegin()).fi,d=min(b[l]-x,y-b[r]);
	//	assert(d>=0);
		if(d<0){puts("NO");return 0;}
	//	assert(r-l+1==SZ(Set));
		if(x==b[l]){
			Set.erase(Set.begin());l++;continue;
		}
		if(y==b[r]){
			Set.erase(Set.rbegin());r--;continue;
		}
		move((*Set.begin()).se,(*Set.rbegin()).se,d);
		Pii zuo=*Set.begin(),you=*Set.rbegin();
		Set.erase(zuo);Set.erase(you);zuo.fi+=d;you.fi-=d;assert(zuo.fi<=you.fi);
		if(zuo.fi==b[l])l++;else Set.insert(zuo);
		if(you.fi==b[r])r--;else Set.insert(you);
	}*/
	puts("YES");
	printf("%d\n",sz);
	rep(i,1,sz)printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
	return 0;
}