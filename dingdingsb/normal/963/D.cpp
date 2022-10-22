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
int n,q,m,mn;char s[N],t[N];
bitset<N>pos[26];
signed main(){
	ios::sync_with_stdio(false);
	cin>>s+1;n=strlen(s+1);
	for(int i=1;i<=n;i++)pos[s[i]-'a'][i]=1;
	cin>>q;
	while(q--){
		cin>>mn>>t+1;m=strlen(t+1);
		bitset<N>ans;ans.set();
		for(int i=1;i<=m;i++)ans&=pos[t[i]-'a']>>i;
		vector<int>res;
		for(int i=ans._Find_first();i!=ans.size();i=ans._Find_next(i))
			res.pb(i);
		if((int)res.size()<mn)puts("-1");
		else{
			int ans=n;
			for(int i=0;i+mn-1<(int)res.size();i++)
				chkmn(ans,res[i+mn-1]-res[i]+m);
			writeln(ans);
		}
	}
}