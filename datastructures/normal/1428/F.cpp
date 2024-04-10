#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
char s[500005];
int n,f[500005];
struct node{
	int l,r;
}c[500005],d[500005];
int len,tot;
inline bool cmp(node a,node b){
	return (a.r-a.l+1)>(b.r-b.l+1);
}
inline bool cmp2(node a,node b){
	return a.l<b.l;
}
inline int calc(int len){
	return len*(len+1)/2;
}
inline int calc2(int n,int m){
	if (m>n)return 0;
	return (n-m+1+n)*m/2;
}
inline int work(int x){
	int ans=0;
	if (x==0){
		for (int i=1;i<=n;i++){
			if (s[i]=='1')continue;
			int j=i;
			while(s[j]=='0')j++;
			j--;
			ans+=(j-i+1)*(j-i+2)/2;
			i=j;
		}
		return ans;
	}
	tot=0;
	for (int i=1;i<=len;i++)
		if (c[i].r-c[i].l+1<=x)break;
		else d[++tot]=c[i];
	sort(d+1,d+1+tot,cmp2);
	for (int i=1;i<=tot;i++){
		int last=1;
		if (i>1)last=d[i-1].r-x+1;
		ans+=calc((d[i].l+x-1)-last+1);
	//	ans+=calc2(d[i].r-d[i].l-1,x);
	}
	int last=1;
	if (tot)last=d[tot].r-x+1;
	ans+=calc(n-last+1);
	return ans;
}
signed main(){
	cin>>n;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='0')continue;
		int j=i;
		while(s[j]=='1')j++;
		j--;
		++len;
		c[len].l=i,c[len].r=j;
		i=j;
	}
	sort(c+1,c+1+len,cmp);
	for (int i=0;i<=n;i++)
		f[i]=work(i);
	for (int i=n;i>=1;i--)
		f[i]-=f[i-1];
	int ans=0;
	for (int i=1;i<=n;i++)ans+=i*f[i];
	cout<<ans<<endl;
	return 0;
} //LHQing_AK_IOI