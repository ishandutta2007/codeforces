#include <iostream>
#include <cstdio>
#define int long long
#define mod 29999997 
using namespace std;
int t,n,m,k,u[1000005],v[1000005],first[1000005],nxt[1000005];
bool book[30000005];
int du[1000005],del[1000005];
int q[1000005],head,tail;
int tot,c[1000005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for (int i=1;i<=m;i++){
			scanf("%lld%lld",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+m]=v[i],v[i+m]=u[i];
			nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
			du[u[i]]++,du[v[i]]++;
			book[(u[i]*n+v[i])%mod]=book[(v[i]*n+u[i])%mod]=1;
		}
		int fg=1;
		if (k*(k-1)<=m*2){
			head=1,tail=0;
			for (int i=1;i<=n;i++)
				if (du[i]<k)q[++tail]=i;
			while(head<=tail){
				int now=q[head];
				++head;
				if (du[now]==k-1){
					tot=0;
					c[++tot]=now;
					for (register int i=first[now];i;i=nxt[i])
						if (del[v[i]]==0)c[++tot]=v[i];
					int nowfg=1;
					for (register int i=1;i<=tot;i++)
						for (register int j=1;j<i;j++)
							if (book[(c[i]*n+c[j])%mod]==0)nowfg=0; 
					if (nowfg==1){
						if (fg==1){
							puts("2");
							for (register int i=1;i<=tot;i++)
								printf("%lld ",c[i]);
							puts("");
							fg=0;
						} 
					} 
				}
				del[now]=1;
				for (register int i=first[now];i;i=nxt[i]){
					du[v[i]]--;
					if (du[v[i]]==k-1)q[++tail]=v[i];
				}
			}
			tot=0;
			for (register int i=1;i<=n;i++)
				if (del[i]==0&&du[i]>=k)c[++tot]=i;
			if (tot>0&&fg==1){
				printf("1 %lld\n",tot);
				for (register int i=1;i<=tot;i++)
					printf("%lld ",c[i]);
				puts("");
				fg=0;
			}
		} 
		if (fg==1)puts("-1");
		for (int i=1;i<=2*m;i++){
			nxt[i]=0;
			book[(u[i]*n+v[i])%mod]=0;
			u[i]=v[i]=0;
		}
		for (int i=1;i<=n;i++)first[i]=du[i]=del[i]=0;
	}
	return 0;
}