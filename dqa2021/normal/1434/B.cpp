#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n;
char s[200010];
int w[200010];
//int id[200010],idtot;
set<int> st;
int stk[200010],stktop;
int ans[200010];
int main()
{
	n=read();
	for (int i=1;i<=n+n;i++){
		char str[3]; scanf("%s",str);
		s[i]=str[0];
		if (s[i]=='-'){
			w[i]=read(); //id[i]=++idtot;
			while (stktop&&w[i]>w[stk[stktop]]) --stktop;
			int t=stk[stktop];
			stk[++stktop]=i;
//			printf("pos %d: %d\n",i,t);
			auto it=st.upper_bound(t);
			if (it==st.end()) return puts("NO"),0;
//			printf("get %d\n",*it);
			ans[*it]=w[i]; st.erase(it);
		}
		else st.insert(i);
	}
	puts("YES");
	for (int i=1;i<=n+n;i++) if (ans[i]) printf("%d ",ans[i]);
	return 0;
}