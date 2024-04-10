#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
vector<pair<int,pii> >all;
int n,a[54];
vector<pii>res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int s=0;
		for(int j=i;j;j--)s+=a[j],all.push_back(mkp(s,mkp(i,j)));
	}
	sort(all.begin(),all.end());
	for(int i=0,j;i<all.size();){
		vector<pii>v;
		for(j=i;j<all.size()&&all[i].fi==all[j].fi;v.push_back(all[j].se),j++);
		int cur=0;
		vector<pii>tmp;
		for(auto x:v)if(x.se>cur)tmp.push_back(x),cur=x.fi;
		if(tmp.size()>res.size())res=tmp;
		i=j;
	}
	printf("%d\n",res.size());
	for(auto x:res)printf("%d %d\n",x.se,x.fi);
}