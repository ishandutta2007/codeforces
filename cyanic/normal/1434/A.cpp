#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=1000005;
int c[N],bas[6],n,tot,cnt,ans=2e9;
pii a[N];

int main(){
	REP(i,6){
		read(bas[i]);
	}
	read(n);
	rep(i,1,n){
		int x;
		read(x);
		REP(j,6){
			if(x>bas[j]){
				a[++tot]=mp(x-bas[j],i);
			}
		}
	}
	sort(a+1,a+tot+1);
	for(int l=1,r=0;l<=tot;l++){
		while(r<tot&&cnt<n){
			++r;
			c[a[r].se]++;
			if(c[a[r].se]==1) cnt++;
		}
		if(cnt==n){
			ans=min(ans,a[r].fi-a[l].fi);
		}
		c[a[l].se]--;
		if(c[a[l].se]==0) cnt--;
	}
	cout<<ans<<endl;
	return 0;
}