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

const int N=2000005;
int n,fir,ans;
char s[N];

void rmain(){
	read(n);
	scanf("%s",s+1);
	fir=1,ans=0;
	for(;fir<n&&s[fir]==s[fir+1];fir++);
	if(fir==n){
		printf("%d\n",1+(n-1)/3);
		return;
	}
	int acc=0;
	rep(i,fir+1,n){
		if(s[i]!=s[i-1]){
			ans+=acc/3;
			acc=0;
		}
		acc++;
	}
	if(s[fir]==s[n]){
		ans+=(fir+acc)/3;
	}
	else{
		ans+=fir/3;
		ans+=acc/3;
	}
	printf("%d\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();

	return 0;
}