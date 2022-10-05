#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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
priority_queue<int> Q;
int n,k,cur;
ll ans,sum;
pii a[N];

int main(){
	read(n);
	rep(i,1,n) read(a[i].fi);
	rep(i,1,n) read(a[i].se);
	sort(a+1,a+n+1),cur=1;
	while(cur<=n||!Q.empty()){
		if(Q.empty()) k=a[cur].fi;
		while(cur<=n&&a[cur].fi==k)
			Q.push(a[cur].se),sum+=a[cur].se,cur++;
		sum-=Q.top(),Q.pop();
		ans+=sum,k++;
	}
	cout<<ans<<endl;
	return 0;
}