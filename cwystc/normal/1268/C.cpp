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
int n,a[500010],w[500010],bit[500010];
LL BIT[500010],ans[500010];
int lowbit(int x){
	return x&-x;
}
int sum(int x){
	int t=0;
	for (;x;x-=lowbit(x)) t+=bit[x];
	return t;
}
void add(int x){
	int t=x;
	for (;x<=n;x+=lowbit(x)) bit[x]++,BIT[x]+=t;
}
LL SUM(int x){
	LL t=0;
	for (;x;x-=lowbit(x)) t+=BIT[x];
	return t;
}
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]),w[a[i]]=i;
	FOR(i,1,n){
		ans[i]=ans[i-1]+i-1-sum(w[i]-1);
		add(w[i]);
	}
	memset(bit,0,sizeof(bit));
	memset(BIT,0,sizeof(BIT));
	FOR(i,1,n){
		add(w[i]);
		int l=1,r=n;
		while (l<r){
			int o=((l+r)>>1);
			if (sum(o)>=(i+1)/2) r=o;
			else l=o+1;
		}
		int L=sum(r);
		//r,r+1
		LL t=SUM(r);
		ans[i]+=1ll*r*L-1ll*L*(L-1)/2-t;
		int R=i-L;
		ans[i]+=(SUM(n)-t)-1ll*r*R-1ll*R*(R+1)/2;
		printf("%lld ",ans[i]);
	}
	return 0;
}