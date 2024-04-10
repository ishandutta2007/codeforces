#include<bits/stdc++.h>
using namespace std;
int n,idx[200003],w[200003],x[200003];
bool cmp1(int a,int b){return w[a]<w[b];}
bool cmp2(int a,int b){return x[a]<x[b];}
int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x[i],&w[i]);
			idx[i]=i;
		}
		sort(idx,idx+m,cmp1);
		sort(idx,idx+2*n,cmp2);
		int ans=0;
		for(int i=0;i<2*n;i++)
			ans+=w[idx[i]];
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			cout<<idx[i]+1<<' '<<idx[2*n-1-i]+1<<endl;
	}
}