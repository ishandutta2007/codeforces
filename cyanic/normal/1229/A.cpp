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

const int N=7005;
ll a[N],q[N],cnt,ans;
int b[N],n;
map<ll,int> cc;

int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,n)++cc[a[i]];
	rep(i,1,n)
		if(cc[a[i]]>=2){
			ans+=b[i];
			q[++cnt]=a[i];
		}
	rep(i,1,n)
		if(cc[a[i]]==1){
			int flag=0;
			rep(j,1,cnt)
				if((a[i]|q[j])==q[j]){
					flag=1;
					break;
				}
			if(flag)ans+=b[i];
		}
	cout<<ans<<endl;
	return 0;
}