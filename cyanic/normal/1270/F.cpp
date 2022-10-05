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

const int N=200005,T=800;
int pos[N],n,m;
char s[N];
ll ans;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n){
		if(s[i]=='1') pos[++m]=i;
	}
	pos[m+1]=n+1;
	int lim=n/T;
	rep(i,1,n){
		int p=lower_bound(pos+1,pos+m+1,i)-pos;
		rep(j,1,min(T,m-p+1)){
			int a=max((ll)(lim+1)*j,(ll)pos[p+j-1]-i+1);
			int b=pos[p+j]-1-i+1;
			if(a<=b) ans+=b/j-(a-1)/j;
		}
	}
//	cout<<ans<<endl;
	rep(i,1,lim){
		unordered_map<ll,int> cnt;
		ll now=0;
		cnt[0]++;
		rep(j,1,n){
			if(s[j]=='1') now+=i-1;
			else now-=1;
//			printf("@ %d %lld %d\n",i,now,cnt[now]);
			ans+=cnt[now];
			cnt[now]++;
		}
	}
	cout<<ans<<endl;
    return 0;
}