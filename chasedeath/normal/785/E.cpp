#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2e5+10,SN=530;
typedef long long ll;
int n,m,a[N],len,s[SN][N],num,blp[N];
ll ans;
void rd(int &s) {
	s=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=(s<<1)+(s<<3)+(x^'0'),x=getchar();
}
void Add(int k,int p) {
	k++;
	while(k<=num) {
		int j=p;
		while(j<=n)s[k][j]++,j+=j&-j;
		k+=k&-k;
	}
}
void Dec(int k,int p) {
	k++;
	while(k<=num) {
		int j=p;
		while(j<=n)s[k][j]--,j+=j&-j;
		k+=k&-k;
	}
}
int Que(int k,int p) {
	k++;
	int res=0;
	while(k) {
		int j=p;
		while(j)res+=s[k][j],j-=j&-j;
		k-=k&-k;
	}
	return res;
}
void Upd(int x,int y) {
	int p1=blp[x],p2=blp[y];
	if(p1==p2) {
		for(int i=x+1; i<y; i++) {
			if(a[i]<a[x])ans--;
			else ans++;
			if(a[i]>a[y])ans--;
			else ans++;
		}
		if(a[x]<a[y])ans++;
		else ans--;
		swap(a[x],a[y]);
		return;
	}
	for(int i=x+1; i<(p1+1)*len; i++) {
		if(a[i]<a[x])ans--;
		else ans++;
		if(a[i]>a[y])ans--;
		else ans++;
	}
	int res1=Que(p2-1,a[y])-Que(p1,a[y]),res2=Que(p2-1,a[x])-Que(p1,a[x]);
	ans+=(res1<<1)-(res2<<1);
	for(int i=p2*len; i<y; i++) {
		if(a[i]<a[x])ans--;
		else ans++;
		if(a[i]>a[y])ans--;
		else ans++;
	}
	if(a[x]<a[y])ans++;
	else ans--;
	Dec(p1,a[x]),Add(p1,a[y]);
	Dec(p2,a[y]),Add(p2,a[x]);
	swap(a[x],a[y]);
}



int main() {
	scanf("%d%d",&n,&m);
	len=sqrt(n);
	len=max(len,1);
	int cnt=0;
	num=n/len+1;
	int s=len;
	for(int i=1; i<=n; i++) {
		if(i>=s)cnt++,s+=len;
		a[i]=i,blp[i]=cnt,Add(cnt,a[i]);
	}
	for(int i=1,x,y; i<=m; i++) {
		rd(x),rd(y);
		if(x>y)swap(x,y);
		if(x!=y)Upd(x,y);
		printf("%lld\n",ans);
	}
}