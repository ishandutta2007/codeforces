#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e3+5,L=2e6+5,Inf=1e9;
struct node{int x,y,z;}c[N*N];
struct point{int x,y;}a[N],b[N];
int n,m,h[L],lef[N],tot;multiset<int>ms;
bool cmp(node a,node b){return a.z<b.z;}
void chkmi(int &x,int y){x=x<y?x:y;}
int main(){
	for(int i=0;i<L;i++)h[i]=Inf;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),chkmi(h[a[i].x],a[i].y);
	for(int i=1;i<L;i++)chkmi(h[i],h[i-1]);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].x,&b[i].y);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i].x<=b[j].x)c[++tot]=(node){i,j,b[j].x-a[i].x+1};
	sort(c+1,c+tot+1,cmp);
	for(int i=1;i<=m;i++){
		lef[i]=b[i].x;
		if(lef[i]>=0&&h[lef[i]]<=b[i].y)ms.insert(b[i].y-h[lef[i]]+1);
	}
	if(ms.empty()||!tot){puts("0");return 0;}
	int ans=*ms.rbegin();
	for(int i=1,x,y;i<=tot;i++){
		x=c[i].x;y=c[i].y;
		if(lef[y]>a[x].x-1){
			if(lef[y]>=0&&h[lef[y]]<=b[y].y){
				auto it=ms.lower_bound(b[y].y-h[lef[y]]+1);
				ms.erase(it);
			}
			lef[y]=a[x].x-1;
			if(lef[y]>=0&&h[lef[y]]<=b[y].y)ms.insert(b[y].y-h[lef[y]]+1);
		}
		if(!ms.empty())ans=min(ans,*ms.rbegin()+c[i].z);else ans=min(ans,c[i].z);
	}
	printf("%d\n",ans);
	return 0;
}