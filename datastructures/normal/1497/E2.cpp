#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,k,val[10000005],book[10000005],a[200005],last[200005],f[200005][25];
int q[25],tail;
inline bool cmp(register int a,register int b){
	return a>b;
}
inline void ins(register int x){
	if (tail<=k)q[++tail]=x;
	else if (x>q[tail])q[tail]=x;
	sort(q+1,q+1+tail,cmp);
	return;
}
int main(){
	for (register int i=1;i<=10000000;i++)val[i]=i;
	for (register int i=2;i*i<=10000000;i++)
		for (register int j=i*i;j<=10000000;j+=i*i)
			while(val[j]%(i*i)==0)val[j]/=i*i;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (register int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=val[a[i]];
		for (register int i=0;i<=n;i++)
			for (register int j=0;j<=k;j++)f[i][j]=1e9;
		f[0][0]=0;
		for (register int i=1;i<=n;i++)book[a[i]]=0;
		for (register int i=1;i<=n;i++)last[i]=book[a[i]],book[a[i]]=i;
		tail=0;
		for (register int i=1;i<=n;i++){
			ins(last[i]);
			for (register int j=1;j<=tail;j++){
				for (register int l=j-1;l<=k;l++)
					f[i][l]=min(f[i][l],f[q[j]][l-(j-1)]+1);
			}
		}
		int ans=1e9;
		for (register int i=0;i<=k;i++)ans=min(ans,f[n][i]);
		cout<<ans<<endl;
	}
	return 0;
}