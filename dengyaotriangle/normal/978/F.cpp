#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

struct inx{
	int i,v;
};

inx f[maxn];
int n,k;
int s[maxn];
int qa[maxn],qb[maxn];
int ans[maxn];
vector<int> x[maxn];

bool cmp(inx a,inx b){
	return a.v<b.v;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
		f[i].v=s[i];
		f[i].i=i;
	}
	sort(f,f+n,cmp);
	for(int i=1;i<n;i++){
		if(f[i].v==f[i-1].v) ans[f[i].i]=ans[f[i-1].i];
		else ans[f[i].i]=i;
	}
	for(int i=0;i<k;i++){
		cin>>qa[i]>>qb[i];
		qa[i]--;
		qb[i]--;
		x[qa[i]].push_back(qb[i]);
		x[qb[i]].push_back(qa[i]);
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<x[j].size();i++){
			if(s[x[j][i]]<s[j]) ans[j]--;
		}
		cout<<ans[j]<<' ';
	}
	return 0;
}