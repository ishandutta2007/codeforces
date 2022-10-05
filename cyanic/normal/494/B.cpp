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

const int N=100005,bas=996,mod=1e9+9,Mod=1e9+7;
int f[N][3],mark[N],pw[N],ha[N],hb,n,m;
char s[N],t[N];

void init(){
	int lim=max(n,m);
	pw[0]=1;
	rep(i,1,lim){
		pw[i]=(ll)pw[i-1]*bas%mod;
	}
	rep(i,1,n){
		ha[i]=((ll)ha[i-1]*bas+s[i])%mod;
	}
	rep(i,1,m){
		hb=((ll)hb*bas+t[i])%mod;
	}
	rep(i,m,n){
		int val=(ha[i]+mod-(ll)ha[i-m]*pw[m]%mod)%mod;
		if(val==hb) mark[i-m+1]=1;
	}
}

void add(int &x,int y){
	x=(x+y>=Mod?x+y-Mod:x+y);
}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	init();
	f[0][0]=1;
	rep(i,1,n){
		add(f[i][0],f[i-1][0]);
		add(f[i][0],f[i-1][2]);
		add(f[i][2],f[i-1][2]);
		if(mark[i]){
			add(f[i+m-1][2],f[i-1][0]);
			add(f[i+m-1][2],f[i-1][1]);
			add(f[i+m-1][2],f[i-1][2]);
		}
		else{
			add(f[i][1],f[i-1][0]);
			add(f[i][1],f[i-1][1]);
			add(f[i][1],f[i-1][2]);
		}
		//printf("# %d : %d %d %d\n",i,f[i][0],f[i][1],f[i][2]);
	}
	int ans=f[n][0];
	add(ans,f[n][2]);
	add(ans,Mod-1);
	cout<<ans<<endl;
	return 0;
}