#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=1005,mod=1e9+7,inv2=(mod+1)/2;
int f[N],p[N],n,ans;

int main(){
	read(n);
	rep(i,1,n){
		read(p[i]);
	}
	per(i,n,1){
		f[i]=1;
		per(j,n,i+1){
			if(p[j]>i) continue;
			f[i]=(f[i]+(ll)inv2*f[j])%mod;
		}
		f[i]=2*f[i]%mod;
		ans=(ans+f[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}