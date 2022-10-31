#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,a[N],ans[N],lst[N],pr[N],l[N];
struct BIT{
    int a[N];
    void add(int k,int p){while(k<=n)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
}T1,T2;
struct Q{int x,y,id;bool operator<(Q b){return y<b.y;}}e[N];

main() {
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i];lst[i]=pr[a[i]],pr[a[i]]=i;
		if(!lst[i]||!lst[lst[i]])l[i]=1;
		else {
			if(i-lst[i]==lst[i]-lst[lst[i]])l[i]=l[lst[i]];
			else l[i]=lst[lst[i]]+1;
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i)
		cin>>e[i].x>>e[i].y,e[i].id=i;
	sort(e+1,e+1+q);
	for(int i=1,j=1;i<=n;++i) {
		T1.add(lst[i]+1,1);T1.add(i+1,-1);
		if(lst[i])T2.add(l[lst[i]],-1),T2.add(lst[i]+1,1);
		T2.add(l[i],1);T2.add(i+1,-1);
		while(e[j].y==i) {
			ans[e[j].id]=T1.sum(e[j].x)+(T2.sum(e[j].x)==0);
			++j;
		}
	}
	for(int i=1;i<=q;++i)
		cout<<ans[i]<<endl;
}