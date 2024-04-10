#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int x[N],y[N];
int f(int a){
	return (a<0?-a:a);
}
int dis(int id1,int id2){
	return f(x[id1]-x[id2])+f(y[id1]-y[id2]);
}
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>x[i]>>y[i];
		for(i=1;i<=n;i++){
			int cnt=0;
			for(j=1;j<=n;j++)
				cnt+=(dis(i,j)<=m);
			if(cnt==n){
				cout<<1<<endl;
				break;
			}
		}
		if(i>n) cout<<-1<<endl;
	}
	return 0;
}