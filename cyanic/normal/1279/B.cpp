#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi frist
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

const int N=100005;
ll s[N],a[N],n,mx,k,ans,lim;

void rmain(){
	read(n);
	read(lim);
	rep(i,1,n){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(s[n]<=lim){
		puts("0");
		return;
	}
	mx=0,k=0;
	rep(i,1,n){
		if(a[i]>mx){
			mx=a[i];
			k=i;
		}
		if(s[i]-mx<=lim){
			ans=k;
		}
	}
	cout<<ans<<endl;
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}