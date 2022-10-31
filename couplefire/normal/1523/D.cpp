#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,p;
ll a[200005];
int f[(1<<15)+5];
int per[200005];
int ans;
ll ans_mask;
int num1(int x){
	int res=0;
	while(x){
		x^=(x&-x);
		res++;
	}
	return res;
}
int main(){
	srand(114514);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		char s[65];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='1')a[i]|=1ll<<j-1;
	}
	for(int i=1;i<=n;i++)per[i]=i;
	random_shuffle(per+1,per+n+1);
	int len=min(30,n-(n+1)/2+1);
	for(int k=1;k<=len;k++){
		vector<int> v;
		for(int i=1;i<=m;i++)
			if(a[per[k]]&(1ll<<i-1))
				v.push_back(i);
		int tot=v.size();
		if(tot<=ans)continue;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			int cur=0;
			for(int j=0;j<tot;j++)
				if(a[i]&(1ll<<v[j]-1))
					cur|=1<<j;
			f[cur]++;
		}
		for(int j=1;j<=tot;j++)
			for(int i=(1<<tot)-1;i>=1;i--)
				if(i&(1<<j-1))
					f[i^(1<<j-1)]+=f[i];
		for(int i=(1<<tot)-1;i>=1;i--)
			if(num1(i)>ans&&f[i]>=(n+1)/2){
				ans=num1(i);
				ans_mask=0;
				for(int j=0;j<tot;j++)
					if(i&(1<<j))ans_mask|=1ll<<v[j]-1;
			}
	}
	for(int i=1;i<=m;i++)
		if(ans_mask&(1ll<<i-1))putchar('1');
		else putchar('0');
	return 0;
}