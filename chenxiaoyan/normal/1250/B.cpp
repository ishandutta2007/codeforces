/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ppf pop_front()
#define X first
#define Y second
const int N=100000;
int n,m;
pair<int,int> a[N+1];
int ans[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].X,a[i].Y=i;
	sort(a+1,a+n+1);
	int now=0;
	while(now<n){
		deque<int> q;priority_queue<int,vector<int>,greater<int> > s;
		q.pb(a[++now].Y);
		int nowt=a[now].X;
		while(true){
			int x=q.front();
			ans[x]=nowt+=m;
			while(now<n&&a[now+1].X<=nowt)a[++now].Y<q.back()?q.pb(a[now].Y):s.push(a[now].Y);
			q.ppf;
			if(q.empty())
				if(s.empty())break;
				else q.pb(s.top()),s.pop();
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
/*1
5 314
0 310 942 628 0
*/
/*2
5 314
0 310 1000000 628 0
*/