#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int n,m,p[100010];
int dp[100010],pre[100010];
struct Rec{
	int val,pos;
}tri[100010];  //init 0
bool operator>(const Rec x,const Rec y)
{
	return x.val>y.val;
}
void add(int x,Rec val)
{
	for (;x;x-=x&-x) if (val>tri[x]) tri[x]=val;
}
Rec query(int x)
{
	Rec res=(Rec){0,-1};
	for (;x<=m;x+=x&-x) if (tri[x]>res) res=tri[x];
	return res;
}
void getlis()
{
	for (int i=1;i<=m;i++) tri[i]=(Rec){0,-1};
	for (int i=n;i;i--)
	{
		Rec x=query(p[i]+1);
		dp[i]=x.val+1,pre[i]=x.pos;
		add(p[i],(Rec){dp[i],i});
	}
}
vector<int> ans[1010]; int anstop;
void init()
{
}
void solve()
{
	m=n=read();
	int K=0; for (;(K+1)*K/2<=n;K++); K--;
	for (int i=1;i<=n;i++) p[i]=read();
	while (n)
	{
		//printf("solve:\n");
		//for (int i=1;i<=n;i++) printf("%d ",p[i]); putchar('\n');
		getlis();
		//for (int i=1;i<=n;i++) printf("%d ",dp[i]); putchar('\n');
		//for (int i=1;i<=n;i++) printf("%d ",pre[i]); putchar('\n');
		int maxpos=-1;
		for (int i=1;i<=n;i++) if (maxpos==-1||dp[i]>dp[maxpos]) maxpos=i;
		if (dp[maxpos]<=K)
		{
			for (int i=1;i<=n;i++) ans[anstop+dp[i]].push_back(p[i]);
			anstop+=dp[maxpos];
			break;
		}
		int tmp=n; n=0;
		anstop++;
		for (int i=1;i<=tmp;i++)
		{
			if (i==maxpos) ans[anstop].push_back(p[i]),maxpos=pre[maxpos];
			else p[++n]=p[i];
		}
		K--;
	}
	printf("%d\n",anstop);
	for (int i=1,tmp;i<=anstop;i++)
	{
		tmp=ans[i].size();
		printf("%d",tmp);
		for (int j=0;j<ans[i].size();j++) printf(" %d",ans[i][j]);
		putchar('\n');
	}
	
	for (int i=1;i<=anstop;i++) vector<int>().swap(ans[i]);
	anstop=0;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	for (int T=read();T--;) init(),solve();
	return 0;
}