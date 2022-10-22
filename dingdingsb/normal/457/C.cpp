#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
const int N=1e5+100;
int n;vector<int>a[N];
int get(int x){
	if(x>n)return 0x3f3f3f3f;
	vector<int>kk;//
	int ans=0,cnt=a[0].size();
	for(int i=1;i<N;i++){
		vector<int>tmp=a[i];
		while(tmp.size()>=x)ans+=tmp.back(),cnt++,tmp.pop_back();
		for(auto x:tmp)kk.pb(x);
	}
	sort(kk.begin(),kk.end());reverse(kk.begin(),kk.end());
	while(cnt<x)ans+=kk.back(),kk.pop_back(),cnt++;
	return ans;
}
signed main(){
	read(n);
	for(int i=1,a,b;i<=n;i++)
		read(a,b),::a[a].pb(b);
	for(int i=1;i<N;i++)
		sort(a[i].begin(),a[i].end()),
		reverse(a[i].begin(),a[i].end());
	int l=1,r=n,ans=0;while(l<=r){
		int mid=(l+r)>>1;
		if(get(mid)<get(mid+1))r=mid-1,ans=mid;
		else l=mid+1;
	}
	write(get(ans));
}