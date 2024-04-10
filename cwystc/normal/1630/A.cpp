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
bool u[500010];
int T,n,k;
void pr(int x,int y){
	u[x]=u[y]=1;
	printf("%d %d\n",x,y);
}
void doit(){
	scanf("%d%d",&n,&k);
	FOR(i,0,n-1) u[i]=0;
	if (k==0){
		FOR(i,0,n-1)
			if (!u[i]) pr(i,i^(n-1));
	}
	else if (k<n-1){
		pr(k,n-1);
		pr(k^(n-1),0);
		FOR(i,0,n-1)
			if (!u[i]) pr(i,i^(n-1));
	}
	else{
		if (n==4){puts("-1");return;}
		pr(n-2,n-1);
		pr(n-3,1);
		pr(0,2);
		FOR(i,0,n-1)
			if (!u[i]) pr(i,i^(n-1));
	}
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}