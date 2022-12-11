#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 110
int n,d[MAXN],s[MAXN],c[MAXN],rk[MAXN],ansl[MAXN],m;
int hv[MAXN];
struct cmp{
	inline bool operator()(int a,int b){
		return d[a]>d[b];
	}
};
priority_queue<int,vector<int>,cmp>q;
inline bool cmp2(int a,int b){
	return s[a]<s[b];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>s[i]>>d[i]>>c[i];
		rk[i]=i;
		if(hv[d[i]]){puts("-1");return 0;}
		hv[d[i]]=true;
	}
	sort(rk+1,rk+1+m,cmp2);
	int cur=1;
	for(int i=1;i<=n;++i){
		while(s[rk[cur]]<=i&&cur<=m){
			q.push(rk[cur]);
			++cur;
		}
		if(hv[i]){
			if(!q.empty())
				if(d[q.top()]<=i){
					//for(int i=1;i<=n;++i)cout<<ansl[i]<<" ";cout<<endl;
					puts("-1");
					return 0;
				}
			ansl[i]=m+1;
		}else{
			if(q.empty()){
				ansl[i]=0;
			}else{
				--c[q.top()];
				ansl[i]=q.top();
				if(!c[q.top()])q.pop();
			}
		}
	}
	for(int i=1;i<=n;++i)cout<<ansl[i]<<" ";cout<<endl;
	return 0;
}