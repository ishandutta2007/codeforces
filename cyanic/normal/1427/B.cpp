#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=200005;
int x[N],n,K,cnt,ans;
char s[N];

void rmain(){
	read(n),read(K);
	scanf("%s",s+1);
	int las=0;
	cnt=ans=0;
	rep(i,1,n){
		if(s[i]=='W'){
			if(las&&las<i-1){
				x[++cnt]=i-1-las;
			}
			las=i;
			ans++;
			if(s[i-1]=='W') ans++;
		}
	}
	int pre=0,suf=n+1;
	for(;pre<n&&s[pre+1]=='L';pre++);
	for(;suf>1&&s[suf-1]=='L';suf--);
	suf=n-suf+1;
	if(pre==n){
		printf("%d\n",max(0,2*K-1));
		return;
	}
	sort(x+1,x+cnt+1);
	rep(i,1,cnt){
		if(K>=x[i]){
			K-=x[i];
			ans+=x[i]*2+1;
		}
		else{
			ans+=K*2;
			K=0;
		}
	}
	if(K>=pre){
		K-=pre;
		ans+=pre*2;
	}
	else{
		ans+=K*2;
		K=0;
	}
	if(K>=suf){
		K-=suf;
		ans+=suf*2;
	}
	else{
		ans+=K*2;
		K=0;
	}
	printf("%d\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();

	return 0;
}