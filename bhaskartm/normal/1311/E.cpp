#include<bits/stdc++.h>
using namespace std;
const int M=5e4+4;
int ans[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int now=(1+n-1)*(n-1)/2;
		if(d>now){
			cout<<"NO"<<endl;
		}
		else{
			for(int i=2;i<=n;i++)
				ans[i]=i-1;
			int flag=1;
			queue<int>que,que2;
			while(!que.empty())
				que.pop();
			while(!que2.empty())
				que2.pop();
			que.push(1);
			int head=1,tail=n;
			while(now!=d){
				if(head+1==tail){
					flag=0;
					break;
				}
				int dec=tail-head-1;
				if(dec>now-d){
					ans[tail]=tail-(now-d)-1;
					break;
				}
				if(que.empty()){
					while(!que2.empty())
						que.push(que2.front()),que2.pop();
					head++;
					que.push(head);
					continue;
				}
				ans[tail]=que.front();
				que.pop();
				que2.push(tail);
				que2.push(tail);
				tail--;
				now-=dec;
			}
			if(flag){
				cout<<"YES"<<endl;
				for(int i=2;i<=n;i++)
					cout<<ans[i]<<' ';
				cout<<'\n';
			}
			else{
				cout<<"NO"<<endl;	
			}
		}
	}
}