#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

struct node{
	int i;
	int s;
	vector <int> l;
};

int n,q;
node x[maxn];
int seq[maxn];
int s[maxn],e[maxn];
int l;

void dfs(int ndidx){
	s[x[ndidx].i]=l;
	seq[l++]=x[ndidx].i;
	for(int i=0;i<x[ndidx].s;i++){
		dfs(x[ndidx].l[i]);
	}
	e[x[ndidx].i]=l;
}

int main(){
	cin>>n>>q;
	x[1].i=1;
	for(int i=2;i<=n;i++){
		x[i].i=i;
		int tmp;
		cin>>tmp;
		x[tmp].l.push_back(i);
		x[tmp].s++;
	}
	dfs(1);
	//for(int i=0;i<l;i++) cout<<seq[i]<<endl;
	while(q--){
		int t1,t2;
		cin>>t1>>t2;
		t2--;
		int idx=s[t1]+t2;
		if(idx>=e[t1]){
			cout<<-1<<endl;
		}else{
			cout<<seq[idx]<<endl;
		}
	}
	return 0;
}