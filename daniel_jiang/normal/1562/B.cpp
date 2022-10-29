// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

int T,n;
string s;

inline bool check(int x){
	if(x<=1) return 1;
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 1;
	return 0;
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s;bool ok=0;
		for(int i=0;i<s.size();++i)
			if(check(s[i]-'0')){
				cout<<1<<endl;
				cout<<s[i];cout<<endl;ok=1;break;
			}
		if(ok) continue;
		for(int i=0;i<s.size()&&!ok;++i)
			for(int j=i+1;j<s.size()&&!ok;++j)
				if(check(10*(s[i]-'0')+s[j]-'0')){cout<<2<<endl<<s[i]<<s[j]<<endl;ok=1;break;}
	}
	return 0;
}

// ---------- Main ---------- //