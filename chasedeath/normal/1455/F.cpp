#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=510,INF=1e9+10;

int n,m;
string s;
string dp[N];
char turn(char a,int k){
	return (a-'a'+k+m)%m+'a';
}
void cmin(string &a,string b){ a=min(a,b); }

int main(){
	rep(_,1,rd()) {
		n=rd(),m=rd();
		cin>>s;
		rep(i,0,n) dp[i]=char('z'+1);
		dp[0]="";
		string ans;
		rep(i,0,n-1) {
			rep(j,-1,1) cmin(dp[i+1],dp[i]+turn(s[i],j));
			if(i) {
				string t=dp[i]; t.pop_back();
				char c=*dp[i].rbegin();
				cmin(dp[i+1],t+s[i]+c);
			}
			if(i<n-1) rep(k,-1,1) dp[i+2]=min(dp[i+2],dp[i]+turn(s[i+1],k)+s[i]);
			if(i && i<n-1) {
				string t=dp[i]; t.pop_back();
				char c=*dp[i].rbegin();
				cmin(dp[i+2],t+s[i+1]+c+s[i]);
			}
		}
		cout<<dp[n]<<endl;
	}
}