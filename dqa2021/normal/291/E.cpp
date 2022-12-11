#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}
const int Mod1=1e9+7,Mod2=998244353;
typedef long long ll;

int n,idtot,lent;
char w[300010],s[300010];
int pow1[300010],pow2[300010],sum1[300010],sum2[300010],h1,h2;
struct Edge{
	int to,nxt;
}edge[300010];
int cnt,last[300010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int rec[300010],ans;
void dfs(int cur)
{
	rec[++*rec]=cur;
	if (cur!=1) sum1[cur]=(29LL*sum1[cur]+w[cur]-'a'+1)%Mod1,
				sum2[cur]=(31LL*sum2[cur]+w[cur]-'a'+1)%Mod2;
	if ((*rec)>=lent&&((ll)sum1[cur]-(ll)sum1[rec[(*rec)-lent]]*pow1[lent]%Mod1+Mod1)%Mod1==h1&&    //rec[(*rec)-lent] not rec[(*rec)-lent+1]
					((ll)sum2[cur]-(ll)sum2[rec[(*rec)-lent]]*pow2[lent]%Mod2+Mod2)%Mod2==h2) ans++;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		sum1[edge[i].to]=sum1[cur]; sum2[edge[i].to]=sum2[cur];
		dfs(edge[i].to);
	}
	(*rec)--;
}

int main()
{
	scanf("%d",&n); idtot=n;   // n and idtot
	for (int i=2,x,len;i<=n;i++)
	{
		read(x); scanf("%s",s+1); len=strlen(s+1);
		if (len==1){w[i]=s[1];addedge(x,i);continue;}
		w[++idtot]=s[1]; addedge(x,idtot);
		for (int j=2;j<len;j++) w[++idtot]=s[j],addedge(idtot-1,idtot);   // i and j
		w[i]=s[len]; addedge(idtot,i);
	}
	scanf("%s",s+1); lent=strlen(s+1);
	for (int i=1;i<=lent;i++) h1=(29LL*h1+s[i]-'a'+1)%Mod1,h2=(31LL*h2+s[i]-'a'+1)%Mod2;
//	printf("hash %d %d\n",h1,h2);
	n=idtot;
	pow1[0]=pow2[0]=1;
	for (int i=1;i<=n;i++)
	{
		pow1[i]=(ll)pow1[i-1]*29%Mod1;
		pow2[i]=(ll)pow2[i-1]*31%Mod2;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}