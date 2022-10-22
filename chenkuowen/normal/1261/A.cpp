#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2005;
char f[MAX_N],s[MAX_N];
set<int> q1,q2;
vector<pair<int,int> > ans;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k; scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int pos=k+k-1-1;
		for(int i=1;i<=pos;i+=2) f[i]='(',f[i+1]=')';
		for(int i=pos+1;i<=n;++i)
			if(i<n-i+pos+1){
//				printf("{%d %d}",i,n-pos+i);
				f[i]='(';
				f[n-i+pos+1]=')';
			}
//		for(int i=1;i<=n;++i) printf("%c",f[i]); puts("");
		q1.clear(); q2.clear(); ans.clear();
		for(int i=1;i<=n;++i)
			if(s[i]=='(') q1.insert(i);
			else q2.insert(i);
		for(int i=1;i<=n;++i){
			if(f[i]=='('){
				int pos=*q1.begin();
				ans.push_back(make_pair(i,pos));
				q1.erase(q1.begin());
	//			printf("<%d>",pos);
				if(pos!=i){
					q2.erase(q2.begin());
					q2.insert(pos);
				}
//				printf("<%d>",pos);
			}else{
				int pos=*q2.begin();
				ans.push_back(make_pair(i,pos));
				q2.erase(q2.begin());
	//			printf("<%d>",pos);
				if(pos!=i){
					q1.erase(q1.begin());
					q1.insert(pos);
				}
		//		printf("<%d>",pos);
			}
//			for(auto x:q1) printf("[%d]",x); puts("");
//			for(auto x:q2) printf("(%d)",x); puts("");
		}
//		puts("B");
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}