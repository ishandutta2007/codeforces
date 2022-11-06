#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const int INF=1e9+10;
int n,m,k,a[500010],ans,b[500010],T;
void doit(){
	cin>>n>>m>>k;
	FOR(i,1,n) getint(a[i]);
	k=min(k,m-1);
	FOR(i,0,m-1) b[i]=max(a[i+1],a[n-(m-1-i)]);
	ans=0;
	FOR(i,0,k){ //i..i+m-1-k
		int t=INF;
		FOR(j,i,i+m-1-k) t=min(t,b[j]);
		ans=max(ans,t);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
	return 0;
}