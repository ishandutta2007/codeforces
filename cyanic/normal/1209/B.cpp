#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=105,M=1005;
int f[N][M],n,a,b;
char s[N];

int main(){
	read(n);
	scanf("%s",s+1);
	rep(i,1,n){
		read(a),read(b);
		int now=s[i]-'0';
		f[i][0]=now;
		rep(k,1,1000){
			if(k>=b&&k%a==b%a)
				now^=1;
			f[i][k]=now;
		}
	}
	int ans=0,c;
	rep(i,0,1000){
		c=0;
		rep(k,1,n)
			c+=f[k][i];
		ans=max(ans,c);
	}
	cout<<ans<<endl;

	return 0;
}