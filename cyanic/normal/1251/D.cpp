#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
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
int l[N],r[N],a[N],b[N];
int n,m,L,R;
ll lim;

int chk(int x){
	vi vec; ll sum=0; int cnt=n/2;
	rep(i,1,n)
		if(r[i]<x)sum+=l[i],cnt--;
		else if(l[i]>x)sum+=l[i]-x;
		else vec.pb(l[i]);
	sort(vec.begin(),vec.end());
	REP(t,vec.size())
		if(cnt)sum+=vec[t],cnt--;
	return sum+(ll)(n/2+1)*x<=lim;
}

void MAIN(){
	read(n),read(lim);
	rep(i,1,n){
		read(l[i]),read(r[i]);
		a[i]=l[i],b[i]=r[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	L=a[n/2+1],R=b[n/2+1];
	while(L<R){
		int mid=(L+R+1)>>1;
		if(chk(mid))L=mid;
		else R=mid-1;
	}
	cout<<L<<endl;
}

int main(){
	int T; read(T);
	while(T--)MAIN();
	return 0;
}