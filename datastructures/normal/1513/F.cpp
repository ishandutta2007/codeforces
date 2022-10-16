#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct node{
	int a,b,c;
}a[200005];
inline bool cmp(register node a,register node b){
	if (a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
int mx1,mx2,d;
long long ans;
int main(){
//	freopen("1513F.in","r",stdin);
//	freopen("1513F.out","w",stdout);
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%d",&a[i].a);
	for (register int i=1;i<=n;i++)scanf("%d",&a[i].b);
	for (register int i=1;i<=n;i++)
		if (a[i].a>a[i].b){
			ans+=a[i].a-a[i].b;
			swap(a[i].a,a[i].b);
			a[i].c=1;
		}
		else{
			ans+=a[i].b-a[i].a;
			a[i].c=2;
		}
	sort(a+1,a+1+n,cmp);
	for (register int i=1;i<=n;i++){
		if (a[i].c==1){
			d=max(d,min(a[i].b,mx2)-a[i].a);
			mx1=max(mx1,a[i].b);
		}
		else{
			d=max(d,min(a[i].b,mx1)-a[i].a);
			mx2=max(mx2,a[i].b);
		}
	}
	cout<<ans-2*d<<endl;
	return 0;
}