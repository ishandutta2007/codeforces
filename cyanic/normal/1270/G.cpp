//sad...
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

const int N=1000005;
int a[N],vis[N],n;

void rmain(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		a[i]=i-a[i];
		vis[i]=0;
	}
	int p=1;
	while(!vis[p]){
		vis[p]=1;
		p=a[p];
	}
	vi ans;
	int aim=p;
	for(;;){
		ans.pb(p);
		p=a[p];
		if(p==aim) break;
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