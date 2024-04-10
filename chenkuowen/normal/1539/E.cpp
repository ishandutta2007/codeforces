#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int pre[N],len[N],type[N],top;
int new_node(int _pre,int _len,int _type){
	++top;
	pre[top]=_pre;
	len[top]=_len;
	type[top]=_type;
	return top;
}
void trunc(set<pair<int,int> >& s,int l,int r){
	while(!s.empty()&&s.begin()->first<l) s.erase(s.begin());
	while(!s.empty()&&prev(s.end())->first>r) s.erase(prev(s.end()));
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	set<pair<int,int> > sl,sr; sl.insert(make_pair(0,1)); sr.insert(make_pair(0,2));
	pre[1]=0; len[1]=0; type[1]=0;
	pre[2]=0; len[2]=0; type[2]=1;
	top=2;
	int lastk=0;
	for(int i=1;i<=n;++i){
		int k,l1,r1,l2,r2; scanf("%d%d%d%d%d",&k,&l1,&r1,&l2,&r2);
		vector<pair<int,int> > gl,gr;
		if(!sl.empty())
			gr.push_back(make_pair(lastk,new_node(sl.begin()->second,i,1)));
		if(!sr.empty())
			gl.push_back(make_pair(lastk,new_node(sr.begin()->second,i,0)));
		for(auto d:gl) sl.insert(d);
		for(auto d:gr) sr.insert(d);
		if(l1<=k&&k<=r1);
		else sl.clear();
		if(l2<=k&&k<=r2);
		else sr.clear();
		trunc(sl,l2,r2);
		trunc(sr,l1,r1);
//		for(auto x:sl) printf("[%d]",x.first); puts("");
//		for(auto x:sr) printf("<%d>",x.first); puts("");
		lastk=k;
	}
	int x=-1;
	if(!sl.empty())	x=sl.begin()->second;
	if(!sr.empty()) x=sr.begin()->second;
	if(x==-1){
		puts("NO");
		exit(0);
	}
	int last=n+1;
	vector<int> ans;
	while(x>0){
		for(int i=len[x];i<last;++i) ans.push_back(type[x]);
		last=len[x]; x=pre[x];
	}
	ans.pop_back();
	reverse(ans.begin(),ans.end());
	puts("Yes");
	for(auto x:ans) printf("%d ",x);
	return 0;
}