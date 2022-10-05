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
 
const int N=1005;
int a[N],b[N],len,n,m;
char s[N];
vi ans;
 
int main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	rep(i,1,len){
		if(s[i]=='(') a[++n]=i;
		else b[++m]=i;
	}
	if(!n||!m||b[m]<a[1]){
		puts("0");
		return 0;
	}
	int p=1,q=m;
	while(p<=n&&q>=1&&a[p]<=b[q]){
		ans.pb(a[p]);
		ans.pb(b[q]);
		p++,q--;
	}
	puts("1");
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x);
	puts("");
	return 0;
}