#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
pair<int,int> a[MAX_N];
int s[MAX_N];
vector<int> g[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=a[i].second*2-1;
		if(i+a[i].first>n&&s[i+a[i].first]==0)
			s[i+a[i].first]=a[i].second*2;
		else
			g[i+a[i].first-1].push_back(a[i].second*2);
	}
	for(int i=1;i<=n+n;++i){
		if(s[i]==0) break;
		if(s[i+1]!=0) printf("%d %d\n",s[i],s[i+1]);
		for(auto j:g[i])
			printf("%d %d\n",s[i],j);
	}
	return 0;
}