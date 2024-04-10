#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,a[100005],c[100005],book[100005],f[100005];
int tot;
vector<int> e[100005];
struct BIT{
	int tree[100005];
	void mem(int n){
		for (int i=0;i<=n;i++)tree[i]=0;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=n)tree[pos]=max(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans=max(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
void work(){
	int len=0;
	bit.mem(n);
	int mx=0;
	for (int i=1;i<=n;i++)
		if (book[i]==0){
			len++;
			f[i]=bit.ask(a[i])+1;
			mx=max(mx,f[i]);
			bit.add(a[i],f[i]);
		}
	if (mx<=c[len]){
		for (int i=1;i<=n;i++)
			if (book[i]==0){
				book[i]=1;
				e[tot+f[i]].push_back(a[i]);
			}
		tot+=mx;
		return;
	}
	++tot;
	int now=mx,qwq=1000000000;
	for (int i=n;i>=1;i--)
		if (book[i]==0){
			if (f[i]==now&&a[i]<=qwq){
				qwq=a[i];
				book[i]=1;
				e[tot].push_back(a[i]);
				now--;
			}
		}
	reverse(e[tot].begin(),e[tot].end());
	work();
	return;
}
int main(){
    cin>>t;
    while(t--){
    	cin>>n;
    	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    	for (int i=1;i<=n;i++){
    		c[i]=c[i-1];
    		while((c[i]+1)*(c[i]+2)/2<=i)c[i]++;
    	}
    	work();
    	for (int i=1;i<=n;i++)book[i]=0;
    	cout<<tot<<endl;
    	for (int i=1;i<=tot;i++){
    		printf("%d ",(int)e[i].size());
    		for (int j=0;j<(int)e[i].size();j++)printf("%d ",e[i][j]);
    		puts("");
    		e[i].clear();
    	}
    	tot=0;
    }
	return 0;
}