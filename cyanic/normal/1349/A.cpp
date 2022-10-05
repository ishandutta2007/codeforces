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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int p[N],flag[N],cnt,n,a;
vi v[N];
ll ans=1;

void init(int lim){
	rep(i,2,lim){
		if(!flag[i]){
			p[++cnt]=i;
			flag[i]=cnt;
		}
		for(int j=1;j<=cnt&&i*p[j]<=lim;j++){
			flag[i*p[j]]=1;
			if(i%p[j]) break;
		}
	}
}

int main(){
	init(200000);
	read(n);
	rep(i,1,n){
		read(a);
		for(int k=1;k<=cnt&&p[k]*p[k]<=a;k++){
			if(a%p[k]) continue;
			int c=0;
			while(a%p[k]==0) a/=p[k],c++;
			v[k].pb(c);
		}
		if(a>=2) v[flag[a]].pb(1);
	}
	rep(i,1,cnt){
		if(v[i].size()<=n-2) continue;
		int mn=(v[i].size()==n-1?0:N),mn2=N;
		for(auto x:v[i]){
			if(x<mn) mn2=mn,mn=x;
			else if(x<mn2) mn2=x;
		}
		while(mn2--) ans*=p[i];
	}
	cout<<ans<<endl;
	return 0;
}