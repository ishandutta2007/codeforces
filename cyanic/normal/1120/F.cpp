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
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int a[N],n,las;
char b[N][2];
ll ans,s,c,d;

int main(){
	read(n),read(c),read(d);
	rep(i,1,n) read(a[i]),scanf("%s",b[i]);
	read(a[n+1]),las=a[n+1],ans=(ll)n*d;
	per(i,n,1){
		if(b[i][0]==b[i+1][0]) s+=min(d,(las-a[i+1])*c);
		else las=a[i+1];
		ans=min(ans,c*(a[n+1]-a[i])+s+d*(i-1));
	}
	cout<<ans<<endl;
	return 0;
}