#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int pa[N],l[N],r[N],R[N],a[N],las[N],cnt[N],mx[N];
int n,q;

inline int getpa(int x){
	return pa[x]==x?x:pa[x]=getpa(pa[x]);
}
inline int getR(int x){
	return R[x]==x?x:R[x]=getR(R[x]);
}

void merge(int a,int b){
	a=getpa(a),b=getpa(b);
	if(a==b)return;
	pa[a]=b;
	l[b]=min(l[b],l[a]);
	r[b]=max(r[b],r[a]);
}

void Link(int x,int y){
	if(getpa(x)==getpa(y)&&getR(x)!=getR(y))
		R[getR(x)]=y;
}

int main(){
	read(n),read(q);
	rep(i,1,n){
		R[i]=pa[i]=l[i]=r[i]=i;
	}
	rep(i,1,n){
		read(a[i]);
		if(las[a[i]])merge(i,las[a[i]]);
		Link(i-1,i);
		las[a[i]]=i,cnt[a[i]]++;
	}
	rep(i,1,n)
		while(getR(l[getpa(i)])<r[getpa(i)]){
			int x=getpa(i),y=getR(l[x])+1;
			if(getpa(x)==getpa(y)){
				Link(x,y);
				continue;
			}
			merge(x,y);
			Link(x,y);
		}
	rep(i,1,n)
		mx[getpa(i)]=max(mx[getpa(i)],cnt[a[i]]);
	int ans=n;
	rep(i,1,n)if(pa[i]==i)
		ans-=mx[i];
	cout<<ans<<endl;
	return 0;
}