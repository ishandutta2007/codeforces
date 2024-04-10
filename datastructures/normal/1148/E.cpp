#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int n,a[300005],b[300005],id[300005];
int sta[300005],tot;
int id1[300005],id2[300005],qwq[300005],len;
struct node{
	int a,id;
}ovo[300005];
bool cmp(node x,node y){
	return x.a<y.a;
}
void work(int x,int y,int z){
	++len;
	id1[len]=id[x],id2[len]=id[y],qwq[len]=z;
	a[x]+=z,a[y]-=z;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&ovo[i].a),ovo[i].id=i;
	sort(ovo+1,ovo+1+n,cmp);
	for (int i=1;i<=n;i++)a[i]=ovo[i].a,id[i]=ovo[i].id;
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++){
		if (a[i]<b[i])sta[++tot]=i;
		while(tot>0&&a[i]>b[i]){
			int awa=min(a[i]-b[i],b[sta[tot]]-a[sta[tot]]);
			work(sta[tot],i,awa);
			if (a[sta[tot]]==b[sta[tot]])tot--;
		}
	}
	int fg=1;
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i])fg=0;
	if (fg==0)puts("NO");
	else{
		puts("YES");
		cout<<len<<endl;
		for (int i=1;i<=len;i++)printf("%d %d %d\n",id1[i],id2[i],qwq[i]);
	}
	return 0;
}