#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[300004],b[300004],fr[300004];
vector<int>f,nf;
set<int>s;
vector<int>ans;
void getans(int x){
	if(x==n)return;
	getans(fr[x]);
	ans.push_back(x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<n;i++)s.insert(i);
	f.push_back(n);
	int lev=0;
	while(!f.empty()){
		lev++;
		while(!f.empty()){
			int x=f.back();f.pop_back();
			int y=x+b[x];
			if(y-a[y]<=0){
				fr[0]=x;
				getans(0);
				printf("%d\n",ans.size());
				for(auto x:ans)printf("%d ",x);
				return 0;
			}
			int L=y-a[y],R=y;
			while(!s.empty()){
				auto it=s.lower_bound(L);
				if(it==s.end())break;
				int p=*it;
				if(p>R)break;
				fr[p]=x;
				s.erase(p);
				nf.push_back(p); 
			}
		}
		swap(f,nf);
	}
	puts("-1");
}