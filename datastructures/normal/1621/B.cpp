#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define int long long
#define inf 1000000000
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,l[100005],r[100005],c[100005];
map<int,int> qwq,qaq,awa;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ml=inf,mr=0;
		qwq.clear(),qaq.clear(),awa.clear();
		for (int i=1;i<=n;i++){
			l[i]=read(),r[i]=read(),c[i]=read();
			ml=min(ml,l[i]);
			mr=max(mr,r[i]);
			if (awa[l[i]*inf+r[i]]==0||awa[l[i]*inf+r[i]]>c[i])awa[l[i]*inf+r[i]]=c[i];
			if (qwq[l[i]]==0||qwq[l[i]]>c[i])qwq[l[i]]=c[i];
			if (qaq[r[i]]==0||qaq[r[i]]>c[i])qaq[r[i]]=c[i];
			int ans=qwq[ml]+qaq[mr];
			if (awa[ml*inf+mr]!=0)ans=min(ans,awa[ml*inf+mr]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}