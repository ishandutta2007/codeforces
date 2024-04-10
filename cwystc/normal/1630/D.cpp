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

pa tmp[500010];
int T,n,l[500100],ts,r[500010];
LL ans;
int a[1000010],b[1000010],mn[1000010],fu[1000010],g,m;

void doit(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) getint(a[i]);
	g=0;
	FOR(i,1,m){
		scanf("%d",&b[i]);
		g=__gcd(g,b[i]);
	}
	
	FOR(i,0,g-1) mn[i]=1e9+10,fu[i]=0;
	FOR(i,1,n) mn[i%g]=min(mn[i%g],abs(a[i])),fu[i%g]+=(a[i]<0);
	LL t=0;
	FOR(i,0,g-1){
		if (mn[i]==0) continue;
		if (fu[i%g]&1) t+=mn[i%g];
	}
	
	ans=t;
	
	bool ok=0;
	FOR(i,1,m) if ((b[i]/g)&1) ok=1;
	if (ok){
		t=0;
		FOR(i,0,g-1){
			if (mn[i]==0) continue;
			if (fu[i%g]%2==0) t+=mn[i%g];
		}
		ans=min(ans,t);
		
	}
	t=0;
	FOR(i,1,n) t+=abs(a[i]);
	printf("%lld\n",t-ans*2);
	
}
int main(){
    
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}