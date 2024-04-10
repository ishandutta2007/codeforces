#include<bits/stdc++.h>
#define int long long 
const int N=105,mod=998244353;
using namespace std;

int K,a,h,pw[N],ans[N];
queue<int>q;
map<int,int> A[2];

void print(int k,int X,int Y){
	int t=1<<K-1;
	while(q.size())q.pop(); 
	for(int i=1;i<=t;i++)q.push(i);
	for(int k=1<<K-2,t=k<<1,cnt=0;k>0;k>>=1,t>>=1)
		for(int j=0;j<k;j++,cnt++){
			int x,y;
			x=q.front();q.pop();
			y=q.front();q.pop();
			if(X>>cnt&1){
				ans[y]=t+1;
				q.push(x);
			}else{
				ans[x]=t+1;
				q.push(y);
			}
		}
	ans[q.front()]=1+k;
	while(q.size())q.pop(); 
	for(int i=t+1;i<=t<<1;i++)q.push(i);
	for(int k=1<<K-2,t=k<<1,cnt=0;k>0;k>>=1,t>>=1)
		for(int j=0;j<k;j++,cnt++){
			int x,y;
			x=q.front();q.pop();
			y=q.front();q.pop();
			if(Y>>cnt&1){
				ans[y]=t+1;
				q.push(x);
			}else{
				ans[x]=t+1;
				q.push(y);
			}
		}
	ans[q.front()]=1+!k;
	for(int i=1;i<=1<<K;i++)
		cout<<ans[i]<<' ';
	exit(0);
}

void solve(int p){
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*a%mod;
	int t=1<<p,co=t-1;
	for(int i=0;i<1<<co;i++){
		int hsh=0;
		for(int i=1;i<=t;i++)q.push(i);
		for(int k=1<<p-1,t=k<<1,cnt=0;k>0;k>>=1,t>>=1)
			for(int j=0;j<k;j++,cnt++){
				int x,y;
				x=q.front();q.pop();
				y=q.front();q.pop();
				if(i>>cnt&1){
					hsh=(hsh+y*pw[t+1])%mod;
					q.push(x);
				}else{
					hsh=(hsh+x*pw[t+1])%mod;
					q.push(y);
				}
			}
		A[0][(hsh+q.front()*pw[1])%mod]=i+1;
		A[1][(hsh+q.front()*pw[2])%mod]=i+1;
		q.pop();
	}
	for(int i=0;i<1<<co;i++){
		int hsh=0;
		for(int i=t+1;i<=t<<1;i++)q.push(i);
		for(int k=1<<p-1,t=k<<1,cnt=0;k>0;k>>=1,t>>=1)
			for(int j=0;j<k;j++,cnt++){
				int x,y;
				x=q.front();q.pop();
				y=q.front();q.pop();
				if(i>>cnt&1){
					hsh=(hsh+y*pw[t+1])%mod;
					q.push(x);
				}else{
					hsh=(hsh+x*pw[t+1])%mod;
					q.push(y);
				}
			}
		int X=(hsh+q.front()*pw[1])%mod,Y=(hsh+q.front()*pw[2])%mod;
		int NX=(h-X+mod)%mod,NY=(h-Y+mod)%mod;
		if(A[0][NY])print(0,A[0][NY]-1,i);
		if(A[1][NX])print(1,A[1][NX]-1,i);
		q.pop();
	}
}

main(){
	ios::sync_with_stdio(false);
	cin>>K>>a>>h;
	solve(K-1);
	cout<<-1<<endl;
}