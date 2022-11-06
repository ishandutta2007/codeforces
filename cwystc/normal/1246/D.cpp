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
vector<int> v[500010],ans,ANS;
int siz[500010],n,fa[500010],len[500010],tmp[500010],ts;
bool cmp(int x,int y){ return (len[x]<len[y]);}
void mkt(int x){
	siz[x]=1;
	len[x]=1;
	FOR(i,0,SZ(v[x])-1){
		int y=v[x][i];
		mkt(y);
		siz[x]+=siz[y];
		len[x]=max(len[x],len[y]+1);
	}
}

void dfs(int x){
	ANS.pb(x);
	ts=0;
	FOR(i,0,SZ(v[x])-1){
		int y=v[x][i];
		tmp[++ts]=y;
	}
	if (!ts) return;
	sort(tmp+1,tmp+ts+1,cmp);
	FORD(i,ts,2){
		ans.pb(tmp[i]);
		v[tmp[i-1]].pb(tmp[i]);
		len[tmp[i-1]]=max(len[tmp[i-1]],len[tmp[i]]+1);
	}
	dfs(tmp[1]);
}
int main(){
	cin>>n;
	FOR(i,2,n) getint(fa[i]),++fa[i],v[fa[i]].pb(i);
	mkt(1);
	dfs(1);
	FOR(i,0,n-1) printf("%d ",ANS[i]-1);
	puts("");
	cout<<SZ(ans)<<endl;
	reverse(ans.begin(),ans.end());
	FOR(i,0,SZ(ans)-1) printf("%d ",ans[i]-1);
	return 0;
}