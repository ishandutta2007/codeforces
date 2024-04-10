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

const int N=1005;
ll x[N],y[N],k,n;

bool chk(){
	int c[2]={0,0};
	rep(i,1,n) c[((x[i]+y[i])%2+2)%2]++;
	k=(!c[0]);
	if(!c[0]||!c[1]) return 0;
	vi ans;
	rep(i,1,n) if(((x[i]+y[i])%2+2)%2) ans.pb(i);
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x);
	return 1;
}

int main(){
	read(n);
	rep(i,1,n) read(x[i]),read(y[i]);
	for(;!chk();){
		rep(i,1,n){
			ll A=x[i],B=y[i];
			x[i]=(A+B+k)/2,y[i]=(A-B+k)/2;
		}		
	}
    return 0;
}