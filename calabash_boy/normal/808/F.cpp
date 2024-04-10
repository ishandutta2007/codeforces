#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXM 100005
int first[MAXN],nxt[MAXM],dis[MAXM],cont[MAXM];
int m,n,k,s,t,tot;
int p[MAXN],c[MAXN],l[MAXN];
bool prm[200005];
int deep[MAXN];
int que[MAXN*10];
bool hasEdge[MAXN][MAXN];
int maxone=-1;
int maxoneindex=-1;
bool bfs(){
	int l=0,r=1;
	que[1]=s;
	memset(deep,0,sizeof(deep));
	while (l<r){
		l++;
		int q = que[l];
		int tt=first[q];
		while (tt!=-1){
//				cout<<next[tt]<<endl;
			if (dis[tt]!=s&&cont[tt]>0&&deep[dis[tt]]==0){
				deep[dis[tt]]=deep[q]+1;
				r++;
				que[r]=dis[tt];
//				cout<<dis[tt]<<endl;
			}
			tt=nxt[tt];
		}
	}
	if (deep[t]==0){
		return false;
	}else{
	
		return true;
	}
}
int dfs(int now,int limit){
//	cout<<"hello"<<endl;
	if (now==t||limit==0){
		return limit;
	}
	if (limit<=0){
		return 0;
	}
	int flow=0,f;
	int tt=first[now];
	while (tt!=-1){
		if (deep[dis[tt]]-deep[now]==1){
			int temp = dfs(dis[tt],min(limit,cont[tt]));
//			if (now==s){
//				cout<<"flow "<<temp<<endl;
//			}
			cont[tt]-=temp;
			cont[tt^1]+=temp;
			limit-=temp;
			flow+=temp;
			if (limit==0){
				break;
			}
		}
		tt=nxt[tt];
	}
	return flow;
}
int maxFlow(int least){
	tot=-1;
	for (int i=0;i<103;i++){
		first[i]=-1;
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (c[i]==1&&i!=maxoneindex){
				continue;
			}
			if (c[j]==1&&j!=maxoneindex){
				continue;
			}
			if (hasEdge[i][j]&&l[i]<=least&&l[j]<=least){
				int ii,jj;
				if (c[i]&1){
					ii=i;
					jj=j;
				}else{
					ii=j;
					jj=i;
				}
				tot++;
				cont[tot]=2147483647;
				dis[tot]=jj;
				nxt[tot]=first[ii];
				first[ii]=tot;
				tot++;
				cont[tot]=0;
				dis[tot]=ii;
				nxt[tot]=first[jj];
				first[jj]=tot;
			}
		}
	}
	int sum =0;
	for (int i=0;i<n;i++){
		if (c[i]==1&&i!=maxoneindex){
			continue;
		}
		if (l[i]<=least){
			sum+=p[i];
			if (c[i]&1){
				tot++;
				cont[tot]=p[i];
				dis[tot]=i;
				nxt[tot]=first[101];
				first[101]=tot;
				tot++;
				cont[tot]=p[i];
				dis[tot]=101;
				nxt[tot]=first[i];
				first[i]=tot;
			}else{
				tot++;
				cont[tot]=p[i];
				dis[tot]=i;
				nxt[tot]=first[102];
				first[102]=tot;
				tot++;
				cont[tot]=p[i];
				dis[tot]=102;
				nxt[tot]=first[i];
				first[i]=tot;
			}
		}
	}
//	for (int i=0;i<n;i++){
//		int tt = first[i];
//		while (tt!=-1){
//			cout<<i<<" connect "<<dis[tt]<<" content "<<cont[tt]<<endl;
//			tt=nxt[tt];
//		}
//	}
	int ans =0;
	while (bfs()){
		ans+=dfs(s,2147483647);
	}
//	cout<<least<<" "<<ans<<" "<<sum-ans<<endl;
	return sum-ans;
} 
int main(){
	memset(prm,true,sizeof(prm));
	prm[0]=prm[1]=false;
	for (int i=2;i<200000;i++){
		if (prm[i]){
			int tmp=i<<1;
			while (tmp<200000){
				prm[tmp]=false;
				tmp+=i;
			}
		}
	}
	cin>>n>>k;
	memset(hasEdge,false,sizeof(hasEdge));
	for (int i=0;i<n;i++){
		cin>>p[i]>>c[i]>>l[i];
		if (c[i]==1&&p[i]>maxone){
			maxone=p[i];
			maxoneindex=i;
		}
		for (int j=0;j<i;j++){
			if (prm[c[i]+c[j]]){
				hasEdge[i][j]=hasEdge[j][i]=true;
			}
		}
	}
	s=101;
	t=102;
		if (maxFlow(101)<k){
		cout<<"-1"<<endl;
		return 0;
	}
//	cout<<"aloha"<<endl;
	int l=0;
	int r=101;
	while (r-l>1){
		int mid =(l+r)>>1;
		if (maxFlow(mid)>=k){
			r=mid;
		}else{
			l=mid;
		}
//		cout<<"nice to meet you"<<endl;
	}
	if (maxFlow(l)>=k){
		cout<<l<<endl;
	}else{
		cout<<r<<endl;
	} 
	return 0;
}