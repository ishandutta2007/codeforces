#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,pa[N],pb[N],a[N],b[N];
struct node{int x1,y1,x2,y2;void print(){printf("%d %d %d %d\n",x1,y1,x2,y2);}};
vector<node>v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pa[a[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),pb[b[i]]=i;
	for(int i=1;i<=n;i++){
		if(a[i]==i&&b[i]==i)continue;int an=a[n],ai=a[i],bn=b[n],bi=b[i];
		if(pa[i]==n){
			if(pb[i]==n)v.push_back((node){i,n,n,i}),pa[a[i]]=n,pb[b[i]]=n,a[n]=a[i],b[n]=b[i];
			else v.push_back((node){i,pb[i],n,i}),pa[a[i]]=n,pb[b[i]]=pb[i],a[n]=a[i],b[pb[i]]=b[i];
		}
		else{
			if(pb[i]==n)v.push_back((node){i,n,pa[i],i}),pa[a[i]]=pa[i],pb[b[i]]=n,a[pa[i]]=a[i],b[n]=b[i];
			else{
				v.push_back((node){i,pb[i],n,i}),v.push_back((node){i,n,pa[i],i});
				if(pa[i]!=i)a[pa[i]]=an,a[n]=ai,pa[an]=pa[i],pa[ai]=n;
				if(pb[i]!=i)b[pb[i]]=bn,b[n]=bi,pb[bn]=pb[i],pb[bi]=n;
			}
		}
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)v[i].print();
	return 0;
}