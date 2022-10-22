#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e3+5;
const ull B=8241207;
int n,m;
int ans[N];
inline ull po(ull x,int k){
	ull ret=1;
	while(k){
		if(k&1) ret=ret*x;
		x=x*x;
		k>>=1;
	}
	return ret;
}
ull ha[N];
int w[N],vis[N];
ull c[N];
int a[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			a[i]=-a[i];
			ha[i]++;
		}
		int x=a[i];
		for(j=2;j*j<=x;j++){
			int cnt=0;
			while(x%j==0){
				cnt++;
				x/=j;
			}
			if(cnt&1)
				ha[i]+=po(B,j);
		}
		if(x>1) ha[i]+=po(B,x);
		c[i]=ha[i];
	}
	sort(c+1,c+n+1);
	for(i=1;i<=n;i++)
		w[i]=lower_bound(c+1,c+n+1,ha[i])-c;
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int answ=0;
		for(j=i;j<=n;j++){
			if(a[j]==0){
				if(answ) ans[answ]++;
				continue;
			}
			if(!vis[w[j]]){
				vis[w[j]]++;
				answ++;
			}
			ans[answ]++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(a[j]!=0) break;
			ans[1]++;
		}
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}