#include<bits/stdc++.h>
using namespace std;
const int B=500;
int n,m,q,ans=1e9;
int f[200004],t;
vector<int>mp[200004];
bool ft[200004];
void chmax(int &A,int B){if(A<B)A=B;}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	bool flg=0;
	if(n>m)swap(n,m),flg=1;
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		if(flg)swap(x,y);
		mp[x].push_back(y);
		if(x==n)ft[y]=1;
	}
	f[1]=1;
	for(int i=0;i<B;i++){
		if(f[n]!=0){
			int tmp=i;
			for(int i=f[n];i<m;){
				int t=i+n;
				if(ft[i])t++;
				i=min(t,m),tmp++;
			}
			ans=min(ans,tmp);
		}
		for(int j=n;j;j--)if(f[j]!=0){
			int t=j+f[j];
			for(auto x:mp[j])if(x==f[j]){t++;break;}
			chmax(f[min(n,t)],f[j]);
			chmax(f[j],min(m,t));
		}
	}
	printf("%d",ans);
}