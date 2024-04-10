#include<bits/stdc++.h>
#define int long long
const int N=1000500;
using namespace std;

int x[N],y[N],dx[N],dy[N],n,m,k,t,sx[N],sy[N];
map<int,int> a[N],b[N];
stack<int> s1,s2;

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		x[n+1]=y[m+1]=0;
		for(int i=1;i<=n;i++)cin>>x[i],dx[x[i]]=i;
		for(int i=1;i<=m;i++)cin>>y[i],dy[y[i]]=i;
		int ans=0;
		for(int i=1;i<=k;i++){
			int X,Y;
			cin>>X>>Y;
			if(dx[X]&&dy[Y])continue;
			if(dx[X]){
				int p=lower_bound(y+1,y+1+m,Y)-y;
//				cout<<dx[X]<<' '<<i<<endl<<endl;
				ans+=sy[p]-a[dx[X]][p];
				sy[p]++,a[dx[X]][p]++; 
				s1.push(dx[X]),s2.push(p);
			}
			else{
				int p=lower_bound(x+1,x+1+n,X)-x;
				ans+=sx[p]-b[p][dy[Y]];
				sx[p]++,b[p][dy[Y]]++; 
				s1.push(p),s2.push(dy[Y]);
			}
		}
		cout<<ans<<endl;
		while(s1.size()){
			sx[s2.top()]=sy[s1.top()]=sx[s1.top()]=sy[s2.top()]=0;
			a[s1.top()][s2.top()]=b[s1.top()][s2.top()]=0;
			s1.pop(),s2.pop();
		} 
		for(int i=1;i<=n;i++)dx[x[i]]=0;
		for(int i=1;i<=m;i++)dy[y[i]]=0;
	}
}