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

const ll N=64;
struct opt{ char c; ll a,b; };
ll a[N],b[N],num[N],x,cnt,flag;
vector<opt> ans;

ll push(ll x){
	num[cnt]=x;
	ll from=1ll<<(cnt++);
//	cerr<<x<<"  "<<cnt<<endl;
	per(i,62,0){
		if(!(x>>i&1)) continue;
		if(a[i]){
			x^=a[i];
			from^=b[i];
			continue;
		}
		if(!i){
			ll las=0;
			REP(j,62) if(from>>j&1){
				if(las){
					ans.pb((opt){'^',las,num[j]});
				}
//				cerr<<j<<" "<<num[j]<<endl;
				las^=num[j];
			}
			assert(las==1);
			return flag=1;
		}
		a[i]=x;
		b[i]=from;
		break;
	}
	if(!x) cnt--;
	return 0;
}

ll R(){
	return rand()%50000+1;
}

int main(){
	read(x);
	for(ll i=1;i<=50000;i++){
		ans.pb((opt){'+',x,i*x});
		if(push(i*x)) break;
	}
//	cerr<<"#"<<endl;
	ll nw=R()*x;
	for(ll i=1;!flag;i++){
		if(nw>1e12) nw=R()*x;
		ll t=R()*x;
		ans.pb((opt){'+',nw,t});
		nw=nw+t;
		if(push(nw)) break;
		t=R()*x;
		ans.pb((opt){'^',nw,t});
		nw=nw^t;
		if(push(nw)) break;
	}
	printf("%d\n",SZ(ans));
	for(auto x:ans){
		printf("%lld %c %lld\n",x.a,x.c,x.b);
	}
	return 0;
}