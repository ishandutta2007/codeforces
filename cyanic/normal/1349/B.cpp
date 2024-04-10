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

const int N=1000005;
int a[N],mn[N],s[N],n,k;

int rmain(){
	read(n),read(k);
	int flag=0;
	rep(i,1,n){
		read(a[i]);
		flag|=(a[i]==k);
	}
	if(!flag) return 0;
	if(n==1) return 1;
	s[0]=mn[0]=0;
	rep(i,1,n){
		s[i]=s[i-1]+(a[i]>=k?1:-1);
		mn[i]=min(mn[i-1],s[i]);
		if(i>=2&&mn[i-2]<s[i]) return 1;
	}
	return 0;
}

int main(){
	int T; read(T);
	while(T--){
		puts(rmain()?"yes":"no");
	}

	return 0;
}