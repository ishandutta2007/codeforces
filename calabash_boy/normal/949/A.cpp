#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
char s[maxn];
vector<int> ans[maxn];int cnt;
int n;
bool used[maxn];
struct Tree{
	int cnt[maxn*4];
	inline void up(int x){
		cnt[x] = cnt[x<<1]+cnt[x<<1|1];
	}
	void build(int x,int l,int r,int dig){
		if (l==r){
			cnt[x] = ((s[l]-'0')==dig);
			return;
		}
		int mid = l+r >>1;
		build(x<<1,l,mid,dig);
		build(x<<1|1,mid+1,r,dig);
		up(x);
	}
	int search(int x,int l,int r,int L,int R){
//		cout<<x<<" "<<l<<" "<<r<<" "<<cnt[x]<<endl;
		if (cnt[x]==0)return -1;
		if (l>R||r<L)return -1;
		if (l==r){
			return l;
		}
		int mid = l+r >>1;
		int temp = search(x<<1,l,mid,L,R);
		if (temp==-1)return search(x<<1|1,mid+1,r,L,R);
		else return temp;
	}
	void add(int x,int l,int r,int index,int delta){
		if (l==r){
			cnt[x]+=delta;
			used[l]=delta==-1;
			return;
		}
		int mid = l+r >>1;
		cnt[x]+=delta;
		if (index<=mid){
			add(x<<1,l,mid,index,delta);
		}else{
			add(x<<1|1,mid+1,r,index,delta);
		}
	}
}t0,t1;
void work(){
	int j = t0.search(1,1,n,1,n);
	ans[cnt].push_back(j);
	t0.add(1,1,n,j,-1);
	int now =0;
	while (true){
//		cout<<j<<endl;
		if (now==0){
			int temp = t1.search(1,1,n,j,n);
			if (temp==-1)break;
			ans[cnt].push_back(temp);
			t1.add(1,1,n,temp,-1);
			now = !now;
			j = temp;
		}else{
			int temp = t0.search(1,1,n,j,n);
			if (temp==-1)break;
			ans[cnt].push_back(temp);
			t0.add(1,1,n,temp,-1);
			now = !now;
			j = temp;
		}
	}
	if (s[ans[cnt][ans[cnt].size()-1]]=='1'){
		t1.add(1,1,n,ans[cnt][ans[cnt].size()-1],1);
		ans[cnt].pop_back();
	}
	cnt++;
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	t0.build(1,1,n,0);
	t1.build(1,1,n,1);
	if (t0.cnt[1]<=t1.cnt[1]){
		cout<<-1<<endl;
		return 0;
	}
	while (t1.cnt[1]){
		int in0 = t0.search(1,1,n,1,n);
		int in1 = t1.search(1,1,n,1,n);
		if (in0==-1||in1<in0){
			cout<<-1<<endl;
			return 0;
		}
		work();
	}
	for (int i=1;i<=n;i++){
		if (!used[i]&&s[i]=='0'){
			ans[cnt++].push_back(i);
		}
	}
	cout<<cnt<<endl;
	for (int i=0;i<cnt;i++){
		printf("%d ",ans[i].size());
		for (int ii=0;ii<ans[i].size();ii++){
			printf("%d ",ans[i][ii]);
		}
		printf("\n");
	}
}