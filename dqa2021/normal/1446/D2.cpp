#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int S=450,U=2e5,INF=0x3f3f3f3f;

int n,a[200010]; int D=-1;
vector<int> b[200010];
int ans;
int c[400010],vrn[400010],tim;
void work1(int x){
	++tim;
	c[U]=0; vrn[U]=tim;
	for (int i=1,T=U;i<=n;i++){
		if (a[i]==D) T++;
		else if (a[i]==x) T--;
		if (vrn[T]^tim) vrn[T]=tim,c[T]=i;
		ans=max(ans,i-c[T]);
	}
}
void work2(int v){
	//printf("work2 %d\n",v);
	++tim;
	int t=b[v].size();
	for (int i=0;i<t;i++){
		int x=b[v][i],pre=i?b[v][i-1]+1:1,suf=i+1<t?b[v][i+1]-1:n;
		int p=lower_bound(b[D].begin(),b[D].end(),x)-b[D].begin(),q=p;
		for (int s=0;s<=t;s++){
			if (s&&b[D][p]<pre) break;
			int pos=pre;
			if (!p);
			else pos=max(pos,b[D][p-1]+1);
			--pos;
			int T=U+p-i;
			//printf("check start %d: val %d\n",pos+1,T-U);
			if (vrn[T]^tim/*||pos<c[T]*/) c[T]=pos,vrn[T]=tim;
			if (!p) break;
			--p;
		}
		for (int s=0;s<=t;s++){
			if (s&&b[D][q-1]>suf) break;
			int pos=suf;
			if (q<int(b[D].size())) pos=min(pos,b[D][q]-1);
			int T=U+q-i-1;
			//printf("check end %d: val %d\n",pos,T-U);
			if (vrn[T]==tim) ans=max(ans,pos-c[T]);
			if (q>=int(b[D].size())) break;
			++q;
		}
	}
}
int main()
{
	n=read();
	int mx=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		b[a[i]].pb(i);
	}
	for (int i=1;i<=n;i++) mx=max(mx,int(b[i].size()));
	for (int i=1;i<=n;i++) if (b[i].size()==mx){
		if (~D) return printf("%d\n",n),0;
		D=i;
	}
	for (int i=1;i<=n;i++)
		if (i==D);
		else if (b[i].size()>=S) work1(i);
		else work2(i);
	printf("%d\n",ans);
	return 0;
}