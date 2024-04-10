#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

const int N=2000005;
struct node{
	char c; int id;
}a[N],b[N];
int n,cnt;
vi ans;

char s[N];

void rmain(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ans.clear();
	rep(i,1,n){
		a[i].c=s[i];
		a[i].id=i;
	}
	cnt=0;
	rep(i,1,n){
		if(3<=i&&i<=n-2&&a[i-2].c=='t'&&a[i-1].c=='w'
			&&a[i].c=='o'&&a[i+1].c=='n'&&a[i+2].c=='e'){
				ans.pb(a[i].id);
		}
		else b[++cnt]=a[i];
	}
	n=cnt,cnt=0;
	rep(i,1,n) a[i]=b[i];
	rep(i,1,n){
		if(2<=i&&i<=n-1&&a[i-1].c=='o'&&a[i].c=='n'&&a[i+1].c=='e'){
			ans.pb(a[i].id);
		}
		else b[++cnt]=a[i];
	}
	n=cnt,cnt=0;
	rep(i,1,n) a[i]=b[i];
	rep(i,1,n){
		if(2<=i&&i<=n-1&&a[i-1].c=='t'&&a[i].c=='w'&&a[i+1].c=='o'){
			ans.pb(a[i].id);
		}
		else b[++cnt]=a[i];
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x);
	puts("");
}

int main(){
	int T; read(T);
	while(T--) rmain();
	
	return 0;
}