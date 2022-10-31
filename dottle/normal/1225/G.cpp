#include<bits/stdc++.h>
#define int long long
const int N=16,P=2005;
using namespace std;

bitset<P> f[1<<N];
int n,k,w[N],s=0,T[N]; 

void calc(int S,int i,int t){
	if(S==0&&i==0)return;
	if(i*k<=s&&f[S][i*k])calc(S,i*k,t+1);
	else{
		for(int j=0;j<n;j++)
			if(S>>j&1){
				if(i>=w[j]&&f[S-(1<<j)][i-w[j]]){
					calc(S-(1<<j),i-w[j],t);
					T[j]=t;
					return ;
				}
			}
	}
}

void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>w[i],s+=w[i];
	f[0][0]=1;
	for(int i=1;i<1<<n;i++){
		for(int j=0;j<n;j++)
			if(i>>j&1)
				f[i]|=f[i-(1<<j)]<<w[j];
		for(int j=s/k;j>=1;j--)
			f[i][j]=f[i][j]|f[i][j*k];
	}
	cout<<(f[(1<<n)-1][1]?"YES":"NO")<<endl;
	if(!f[(1<<n)-1][1])exit(0);
	calc((1<<n)-1,1,0);
	priority_queue<pair<int,int>>q;
	for(int i=0;i<n;i++)q.push({T[i],w[i]});
	while(q.size()>1){
		auto n1=q.top();q.pop();
		auto n2=q.top();q.pop();
		cout<<n1.second<<' '<<n2.second<<endl;
		n1.second+=n2.second;
		while(n1.second%k==0)n1.second/=k,n1.first--;
		q.push(n1);
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}