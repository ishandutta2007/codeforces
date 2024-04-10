#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int n,a[1000005],d[1000005];
char b[1000005];
struct node{
	int pos,cnt;
};
node make_node(int pos,int cnt){
	node ans;
	ans.pos=pos,ans.cnt=cnt;
	return ans;
}
vector<node> c[1000005];
int suf[1000005],nxt[1000005];
int q[1000005],tail;
struct qwq{
	int l,r,val;
}qaq[8000005];
bool cmp(qwq a,qwq b){
	return a.r>b.r;
}
int tot;
int f[1000005];
ll ans;
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		memset(tree,0x3f,sizeof(tree));
		maxn=1000000;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=min(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=1e9;
		while(pos)ans=min(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",b+1);
	for (int i=2;i<=1000000;i++){
		if (d[i]!=0)continue;
		for (int j=i;j<=1000000;j+=i)
			if (d[j]==0)d[j]=i;
	}
	for (int i=1;i<=n;i++){
		int x=a[i];
		while(x>1){
			int awa=d[x],cnt=0;
			while(d[x]==awa)cnt++,x/=awa;
			if (b[i]=='*')c[awa].push_back(make_node(i,cnt));
			if (b[i]=='/')c[awa].push_back(make_node(i,-cnt));
		}
	}
	for (int i=1;i<=1000000;i++){
		int len=c[i].size();
		if (len==0)continue;
		suf[len]=0;
		tail=0;
		for (int j=len-1;j>=0;j--){
			suf[j]=suf[j+1]+c[i][j].cnt;
			if (c[i][j].cnt<0)nxt[j]=j;
			else if (tail&&suf[q[1]+1]>suf[j]){
				int l=1,r=tail,quq=0;
				while(l<=r){
					int mid=(l+r)/2;
					if (suf[q[mid]+1]>suf[j])quq=mid,l=mid+1;
					else r=mid-1;
				}
				nxt[j]=q[quq];
			}
			else nxt[j]=n+1;
			while(tail>0&&suf[q[tail]+1]<=suf[j+1])tail--;
			q[++tail]=j;
		}
		int last=0;
		for (int j=0;j<len;j++){
			if (nxt[j]<=n){
				++tot;
				qaq[tot].l=last+1,qaq[tot].r=c[i][j].pos,qaq[tot].val=c[i][nxt[j]].pos;
			}
			last=c[i][j].pos;
		}
	}
	for (int i=1;i<=n;i++)f[i]=n+1;
	sort(qaq+1,qaq+1+tot,cmp);
	int j=1;
	for (int i=n;i>=1;i--){
		while(j<=tot&&qaq[j].r>=i)bit.add(qaq[j].l,qaq[j].val),j++;
		f[i]=min(f[i],bit.ask(i));
	}
	for (int i=1;i<=n;i++)ans+=f[i]-i;
	cout<<ans<<endl;
	return 0;
}