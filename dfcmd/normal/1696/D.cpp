#include<bits/stdc++.h>
using namespace std;
#define N 270000
typedef long long ll;
int n,a[N],lg[N],dp[N];
class ST_Table_max{
public:
	int f[N][19];
	void Insert(int u,int w){
		f[u][0]=w;
		for(int i=1;u-(1<<i)+1>=1&&i<=18;++i){
			f[u][i]=max(f[u][i-1],f[u-(1<<i-1)][i-1]);
		}
	}
	int Query(int l,int r){
		int k=lg[r-l+1];
		return max(f[r][k],f[l+(1<<k)-1][k]);
	}
}T1;
class ST_Table_min{
public:
	int f[N][19];
	void Insert(int u,int w){
		f[u][0]=w;
		for(int i=1;u-(1<<i)+1>=1&&i<=18;++i){
			f[u][i]=min(f[u][i-1],f[u-(1<<i-1)][i-1]);
		}
	}
	int Query(int l,int r){
		l=max(l,1);
		if(l>r)return n+1;
		int k=lg[r-l+1];
		return min(f[r][k],f[l+(1<<k)-1][k]);
	}
}T2,W1,W2;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	static int st1[N],top1,st2[N],top2,mx1[N],mn2[N];
	top1=top2=0;
	dp[1]=0;
	auto Ask1=[&](int lim)->int{
		int l=1,r=top1+1,ans=top1+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(T1.Query(mid,top1)<lim){
				ans=mid;
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		return ans-1;
	};
	auto Ask2=[&](int lim)->int{
		int l=1,r=top2+1,ans=top2+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(T2.Query(mid,top2)>lim){
				ans=mid;
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		return ans-1;
	};
	for(int i=1;i<=n;++i){
		int t1=a[i],t2=a[i];
		while(top1&&a[i]<a[st1[top1]]){
			t1=max(t1,mx1[top1]);
			--top1;
		}
		while(top2&&a[i]>a[st2[top2]]){
			t2=min(t2,mn2[top2]);
			--top2;
		}
		if(i>1){
			dp[i]=min(t1==a[i]?W1.Query(Ask1(a[i]),top1):n,t2==a[i]?W2.Query(Ask2(a[i]),top2):n)+1;
		}
		st1[++top1]=i;
		mx1[top1]=t1;
		st2[++top2]=i;
		mn2[top2]=t2;
		W1.Insert(top1,dp[i]);
		W2.Insert(top2,dp[i]);
		T1.Insert(top1,t1);
		T2.Insert(top2,t2);
	}
	cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=2;i<=250000;++i){
		lg[i]=lg[i>>1]+1;
	}
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}