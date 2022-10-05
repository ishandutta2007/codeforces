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

const int N=1000005;
int a[N],b[N],n;
char s[N];

int chk(int t){
	int mn0=0,mn1=t;
	rep(i,1,n)
		if(a[i]>t||a[i]==t&&mn1==t){
			b[i]=2;
			if(a[i]<mn1)return 0;
			mn1=a[i];
		}
		else{
			b[i]=1;
			if(a[i]<mn0)return 0;
			mn0=a[i];
		}
	return 1;
}

void MAIN(){
	read(n);
	scanf("%s",s+1);
	rep(i,1,n)a[i]=s[i]-'0';
	rep(t,0,9)
		if(chk(t)){
			rep(i,1,n)printf("%d",b[i]);
			puts("");
			return;
		}
	puts("-");
}

int main(){
	int T; read(T);
	while(T--)MAIN();
	return 0;
}