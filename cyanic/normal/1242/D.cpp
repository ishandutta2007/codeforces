#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
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

ll n,k,l;

ll calc(ll i){
	if(i==0) return k*(k+1)/2;
	ll bas=i/k*l,p=bas+calc(i/k);
	ll le=bas+i%k*k+1,ri=le+k-1;
	if(p<=le) le++,ri++;
	else if(le<=p&&p<=ri) ri++;
	ll s=(le+ri)*(ri-le+1)/2;
	if(le<=p&&p<=ri) s-=p;
	return s-i*l;
}

void rmain(){
	read(n),read(k),l=k*k+1;
	ll i=(n-1)/l,p=calc(i);
	if((n-1)%l+1==p) printf("%lld\n",(i+1)*(k+1));
	else{
		ll ans=i*(l-1)+i*k,t=n-i*l;
		if(p<t) t--;
		ans+=t+(t-1)/k;
		printf("%lld\n",ans);
	}
}

int main(){
	int T; read(T);
	while(T--) rmain();	
	return 0;
}