#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define INF n+1
int n,q;
vector<int> E[MAX];
int minNum[MAX];
int que[MAX*5];
int deep[MAX];
int root;
int last = 0;
int ans ;
void init(){
	cin>>n>>q;
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%d%d",&root,&root);
	root = root%n+1;
	ans = root;
	q--;
	for (int i=0;i<=n;i++){
		minNum[i] = i;
	}
} 
void initBuild(){
	int l =0,r=1;
	que[1] = root;
	deep[root] = 1;
	while (l<r){
		l++;
		int a = que[l];
		for (vector<int>::iterator it = E[a].begin();it!=E[a].end();it++){
			if (deep[(*it)]==0){
				deep[(*it)] = deep[a]+1;
				r++;
				que[r] = (*it);
			}
		}
	}
}
void build (){
	initBuild();
	int l=0,r=1;
	que[1]=root;
	minNum[root] = root;
	while (l<r){
		l++;
		int a = que[l];
		int temp = minNum[a];
		for (vector<int>::iterator it = E[a].begin();it!=E[a].end();it++){
			if (deep[(*it)]>deep[a]){
				minNum[(*it)] = min(temp,minNum[(*it)]);
				r++;
				que[r] = (*it);
			}
		}
	}
}
void solve(){
	while (q--){
		int flag,index;
		scanf("%d%d",&flag,&index);
		index = (index+last)%n+1;
		if (flag==1){
			ans = min (ans,minNum[index]);
		}else{
			last  = min(ans,minNum[index]);
			printf("%d\n",last);
		}
	}
}
int main(){
	init();	
	build();
//	cout<<endl;
//	for (int i=1;i<=n;i++){
//		cout<<minNum[i]<<" ";
//	}
//	cout<<endl;
	solve();
	return 0;
}