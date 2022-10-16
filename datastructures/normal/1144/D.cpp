#include <iostream>
#include <cstdio>
#define ccf f***
using namespace std;
int a[300005],n;
int book[200005],s[300005],maxnow,k,tot;
int used[200005];
void out(int i,int j){
	if (a[i]<a[j])cout<<1<<' '<<i<<' '<<j<<endl;
	else cout<<2<<' '<<i<<' '<<j<<endl;
	return; 
}
int main(){
//	freopen("1144D.in","r",stdin);
//	freopen("1144D.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
		book[a[i]]++;
	for (int i=0;i<=200000;i++)
		if (book[i]>maxnow)k=i,maxnow=book[i];
	for (int i=1;i<=n;i++)
		if (a[i]==k)s[++tot]=i,used[i]=1;
	cout<<n-maxnow<<endl;
	for (int i=1;i<=tot;i++){
		for (int now=s[i]-1;now;now--){
			if (used[now])break;
			used[now]=1;
			out(now,now+1);
			a[now]=a[now+1];
		}
		for (int now=s[i]+1;now<=n;now++){
			if (used[now])break;
			used[now]=1;
			out(now,now-1);
			a[now]=a[now-1];
		}
	}
	return 0;
}