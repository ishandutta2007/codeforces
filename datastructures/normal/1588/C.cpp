#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <random>
#include <ctime>
#define int long long
using namespace std;
mt19937 rnd(time(NULL));
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int t,n,a[300005];
int d[2][300005],s[2][300005];
int nxt[300005];
vector<int> del[300005];
map<int,int> c[2];
int val[300005];
int q[300005],tail;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++){
			if (i&1)d[1][i]=a[i],d[0][i]=-a[i];
			else d[0][i]=a[i],d[1][i]=-a[i];
			s[0][i]=s[0][i-1]+d[0][i];
			s[1][i]=s[1][i-1]+d[1][i];
		}
		for (int i=1;i<=n;i++)nxt[i]=n+1;
		int lst;

		val[0]=val[1]=0;
		for (int i=2;i<=n;i+=2)val[i]=val[i-2]+a[i]-a[i-1];
		if (n&1)lst=n-1;
		else lst=n;
		tail=0;
		for (int i=lst;i>=1;i-=2){
			if (tail>0&&val[q[1]]<val[i]-a[i]){
				int l=1,r=tail,pos=0;
				while(l<=r){
					int mid=(l+r)/2;
					if (val[q[mid]]<val[i]-a[i])pos=mid,l=mid+1;
					else r=mid-1;
				}
				nxt[i]=min(nxt[i],q[pos]);
			}
			if (i>1&&tail>0&&val[q[1]]<val[i-2]){
				int l=1,r=tail,pos=0;
				while(l<=r){
					int mid=(l+r)/2;
					if (val[q[mid]]<val[i-2])pos=mid,l=mid+1;
					else r=mid-1;
				}
				nxt[i-1]=min(nxt[i-1],q[pos]);
			}
			while(tail>0&&val[q[tail]]>=val[i])tail--;
			q[++tail]=i;
		}

		val[0]=val[1]=val[2]=0;
		for (int i=3;i<=n;i+=2)val[i]=val[i-2]+a[i]-a[i-1];
		if (n&1)lst=n;
		else lst=n-1;
		tail=0;
		for (int i=lst;i>=1;i-=2){
			if (tail>0&&val[q[1]]<val[i]-a[i]){
				int l=1,r=tail,pos=0;
				while(l<=r){
					int mid=(l+r)/2;
					if (val[q[mid]]<val[i]-a[i])pos=mid,l=mid+1;
					else r=mid-1;
				}
				nxt[i]=min(nxt[i],q[pos]);
			}
			if (i>1&&tail>0&&val[q[1]]<val[i-2]){
				int l=1,r=tail,pos=0;
				while(l<=r){
					int mid=(l+r)/2;
					if (val[q[mid]]<val[i-2])pos=mid,l=mid+1;
					else r=mid-1;
				}
				nxt[i-1]=min(nxt[i-1],q[pos]);
			}
			while(tail>0&&val[q[tail]]>=val[i])tail--;
			q[++tail]=i;
		}
		for (int i=1;i<n;i++)
			if (a[i+1]<a[i])nxt[i]=i+1;
		int ans=0;
		for (int i=1;i<=n;i++)del[nxt[i]].push_back(i);
		for (int i=1;i<=n;i++){
			for (int j=0,len=del[i].size();j<len;j++)c[0][s[0][del[i][j]-1]]--,c[1][s[1][del[i][j]-1]]--;
			c[0][s[0][i-1]]++;
			c[1][s[1][i-1]]++;
			ans+=c[i&1][s[i&1][i]];
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)s[0][i]=s[1][i]=0;
		for (int i=1;i<=n+1;i++)del[i].clear();
		c[0].clear();
		c[1].clear();
	}
	return 0;
}