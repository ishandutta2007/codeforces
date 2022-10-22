#include<bits/stdc++.h>
using namespace std;
short pre[20][5000005];
int a[20],s[20];
long long pw[20];
bool vis[5000005];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int top=0; pw[0]=1; 
	while(pw[top]<n*2000) pw[top+1]=pw[top]*k,++top;
	memset(pre,-1,sizeof(pre));
	pre[0][0]=0;
	for(int i=1;i<=top;++i) vis[pw[i]]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=pw[top];++j)
			for(int t=0;pw[t]*a[i]<=j;++t){
				if(pre[i-1][j-pw[t]*a[i]]!=-1){
					pre[i][j]=t;
					break;
				}
			}
	}
	for(int i=0;i<=pw[top];++i)
		if(pre[n][i]!=-1&&vis[i]){
			int x=i;
			for(int j=n;j>=1;--j){
				s[j]=pre[j][x];
				x-=pw[pre[j][x]]*a[j];
			}
			goto __flag1;
		}
	puts("NO");
	return 0;
	__flag1:;
	puts("YES");
	priority_queue<pair<int,int>,vector<pair<int,int> >
		,greater<pair<int,int> > > q;
	for(int i=1;i<=n;++i) q.push(make_pair(s[i],a[i]));
	while(q.size()>1){
		int x=q.top().second,cnt=q.top().first; q.pop();
		while(x%k!=0){
			printf("%d %d\n",x,q.top().second);
			x+=q.top().second; q.pop();
		}
		while(x%k==0) x/=k,++cnt;
		q.push(make_pair(cnt,x));
	}
	return 0;
}