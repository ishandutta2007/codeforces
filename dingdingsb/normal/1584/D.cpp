//

// Problem: B. Guess the Permutation
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.ml/contest/1588/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
int t,n;map<int,int>kk;
int ask(int l,int r){
	int x;cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;return x;
}
int get(int x){
	int l=0,r=1e9+10,ans=0;
	while(l<=r){
		if(mid*(mid-1)/2<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int l=2,r=n,i;
		while(l<=r){
			if(ask(1,mid))i=mid,r=mid-1;
			else l=mid+1;
		}
		i--;
		int kk=ask(i+1,n);
		int len=ask(i,n)-kk;
		int j=i+len+1;
		int kkk=ask(j,n);
		int k=j+get(kkk)-1;
		cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
	}
}