#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int t,n,a[1000005],len;
int d[1000005];
int ans1[1000005][2],tot1,ans2[1000005],tot2;
int p;
void ins(int x){
	a[++len]=x;
	if (p<len&&a[p]==x){
		int l=p+1,r=len-1;
		int awa=2*(len-p);
		ans2[++tot2]=awa;
		for (int i=l;i<=r;i++){
			++tot1;
			ans1[tot1][0]=len,ans1[tot1][1]=a[i];
			++len;
			a[len]=a[i];
		}
		p=len+1;
		for (int i=r;i>=l;i--)ins(a[i]);
	}
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		len=tot1=tot2=0;
		p=1;
		for (int i=1;i<=n;i++){
			scanf("%d",&d[i]);
			ins(d[i]);
		}
		sort(d+1,d+1+n);
		int fg=1;
		if (n&1)fg=0;
		for (int i=2;i<=n;i+=2)
			if (d[i]!=d[i-1])fg=0;
		if (fg==0){
			puts("-1");
			continue;
		}
		cout<<tot1<<endl;
		for (int i=1;i<=tot1;i++)printf("%d %d\n",ans1[i][0],ans1[i][1]);
		cout<<tot2<<endl;
		for (int i=1;i<=tot2;i++)printf("%d ",ans2[i]);
		cout<<endl;
	}
	return 0;
}