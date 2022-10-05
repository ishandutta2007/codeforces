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

const int N=1000005;
int a[N],b[N],p[N],n,ans;

int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]),p[b[i]]=i;
	int mx=0;
	rep(i,1,n){
		if(p[a[i]]<mx)ans++;
		mx=max(mx,p[a[i]]);
	}
	cout<<ans<<endl;

	return 0;
}