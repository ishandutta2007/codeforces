#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int m,k,n,s,a[500005],b[500005];
int book[500005],booknow[500005],nowcnt,fg;
int ansl,ansr,ans[500005];
inline void work(int l,int r){
	memset(booknow,0,sizeof(booknow));
	int tot1=0,tot2=0,tot3=0;
	for (int i=l;i<=r;i++){
		if (booknow[a[i]]<book[a[i]]){
			++tot2;
			booknow[a[i]]++;
			ans[i]=1;
		}
	}
	for (int i=l;i<=r;i++){
		if (ans[i]==1)continue;
		if (tot2<k)ans[i]=1,tot2++;
	}
	tot1=(l-1)/k*k;
	tot1=min(tot1,n*k-tot2);
	tot3=(m-r)/k*k;
	tot3=min(tot3,n*k-tot1-tot2);
	for (int i=1;i<=tot1;i++)ans[i]=1;
	for (int i=m-tot3+1;i<=m;i++)ans[i]=1;
	return;
}
int main(){
	cin>>m>>k>>n>>s;
	for (int i=1;i<=m;i++)scanf("%d",&a[i]);
	for (int i=1;i<=s;i++)scanf("%d",&b[i]);
	for (int i=1;i<=s;i++)book[b[i]]++;
	int r=0;
	for (int i=1;i<=m;i++){
		while((nowcnt<s||r-i+1<k)&&r<m){
			++r;
			booknow[a[r]]++;
			if (booknow[a[r]]<=book[a[r]])nowcnt++;
		}
		if (nowcnt<s)break;
		if ((i-1)/k+(m-r)/k+1>=n){
			ansl=i,ansr=r;
			fg=1;
			break;
		}
		booknow[a[i]]--;
		if (booknow[a[i]]<book[a[i]])nowcnt--;
	}
	if (fg==0){
		cout<<-1<<endl;
		return 0;
	}
	work(ansl,ansr);
	cout<<m-n*k<<endl;
	for (int i=1;i<=m;i++)
		if (ans[i]==0)printf("%d ",i);
	cout<<endl; 
	return 0;
}