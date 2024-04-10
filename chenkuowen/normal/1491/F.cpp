#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int query(vector<int> a,vector<int> b){
	printf("? %d %d\n",(int)a.size(),(int)b.size());
	for(auto x:a) printf("%d ",x); puts("");
	for(auto x:b) printf("%d ",x); puts("");
	fflush(stdout);
	int ret; scanf("%d",&ret);
	return ret;
}
int a[N];
int find(vector<int> s,int x){
	if(s.size()==1) return s[0];
	int m=s.size()/2;
	vector<int> a(s.begin(),s.begin()+m),b(s.begin()+m,s.end());
	if(query(a,{x})!=0) return find(a,x);
	else return find(b,x);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) a[i]=-1;
		vector<int> f;
		for(int i=1;i<=n;++i){
			if(f.empty()){
				f.push_back(i);
				continue;
			}
			if(a[f[0]]==-1){
				if(query(f,{i})!=0){
					int x=find(f,i);
					a[i]=0;
					a[x]=0;
					f=vector<int>({x});
				}else f.push_back(i);
			}else if(query(f,{i})!=0) a[i]=0;
			else a[i]=-1;
		}
		vector<int> ret;
		for(int i=1;i<=n;++i)
			if(a[i]==-1) ret.push_back(i);
		printf("! %d ",(int)ret.size());
		for(auto x:ret) printf("%d ",x);
		puts("");
		fflush(stdout);
	}
	return 0;
}