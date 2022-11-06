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
int T,n,l[500100],ts,r[500010],ans;
int a[500010];

void doit(){
	scanf("%d",&n);
	FOR(i,1,n) l[i]=n+1,r[i]=0;
	FOR(i,1,n) scanf("%d",&a[i]),l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	ts=0;
	FOR(i,1,n) if (l[i]<r[i]){
		tmp[++ts]=mp(l[i],r[i]);
	}
	
	if (ts==0){
		puts("0");
		return;
	}
	
	sort(tmp+1,tmp+ts+1);
	
	int TS=1;
	FOR(i,2,ts) if (tmp[i].se>tmp[TS].se) tmp[++TS]=tmp[i];
	ts=TS;
	
	ans=0;
	int too=0;
	FOR(i,1,ts){
		if (tmp[i].fi<too){
			while (i<ts && tmp[i+1].fi<too) ++i;
		}
		if (tmp[i].fi>=too){
			ans+=tmp[i].se-tmp[i].fi-1;
		}
		else{
			ans+=tmp[i].se-too-1;
		}
		too=tmp[i].se;
	}
	printf("%d\n",ans);
}
int main(){
    
	T=1;
	while (T--) doit();
    return 0;
}