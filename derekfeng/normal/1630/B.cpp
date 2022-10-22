#include<bits/stdc++.h>
using namespace std;
int n,K,cnt[200004],a[200004];
void sol(){
	scanf("%d%d",&n,&K);for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	int sum=0,ans=1e9,L,R;
	int lb=1;
	for(int i=1;i<=n;i++){
		sum+=cnt[i];
		while(sum-cnt[lb]>=(n+K+1)/2)sum-=cnt[lb],lb++;
		if(sum>=(n+K+1)/2&&i-lb<ans)
			ans=i-lb,L=lb,R=i;
	}
	printf("%d %d\n",L,R);
	vector<int>p,q;
	int cur=0;
	for(int i=1;i<K;i++){
		int nxt=cur+1,tmp=0;
		for(;;++nxt){
			tmp+=(L<=a[nxt]&&a[nxt]<=R)?1:-1;
			if(tmp==1)break;
		}
		p.push_back(cur+1),q.push_back(nxt);
		cur=nxt;
	}
	p.push_back(cur+1),q.push_back(n);
	for(int i=0;i<K;i++)printf("%d %d\n",p[i],q[i]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}