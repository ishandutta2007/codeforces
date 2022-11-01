#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 100005;
unsigned top;
int T, n, pre[N], id[N], s[N];
vector<int> a;
vector<vector<int>> ans;
inline int find(int x){
	int l=0, r=top-1, ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(x<s[mid]) ans=mid, r=mid-1; else l=mid+1;
	}
	return ans;
}
inline void solve(){
	if(!a.size()) return;
	top=1;
	s[0]=a[0];
	id[a[0]]=0, pre[a[0]]=0;
	for(unsigned i=1; i<a.size(); ++i)
		if(a[i]>s[top-1]) pre[a[i]]=s[top-1], id[a[i]]=top, s[top++]=a[i];
		else{
			id[a[i]]=find(a[i]);
			pre[a[i]]=(id[a[i]]?s[id[a[i]]-1]:0), s[id[a[i]]]=a[i];
		}
	unsigned lim=(sqrt(a.size()*8+1)-1)/2;
	if(top<=lim){
		// printf(">> %d\n", s.size());
		ans.resize(top);
		for(int i:a) /*printf("-- %d\n", id[i]), */ans[id[i]].push_back(i);
	}
	else{
		unsigned j=0, k=0;
		vector<int> t;
		for(int i=s[top-1]; i; i=pre[i]) t.push_back(i);
		reverse(t.begin(), t.end());
		// for(int i:t) printf("[%d]", i); puts("");
		for(int i:a) if(j<t.size() && i==t[j]) j++; else a[k++]=i;
		a.resize(k), solve(), ans.push_back(t);
	}
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n), a.resize(n);
		for(int i=0; i<n; ++i) scanf("%d", &a[i]);
		ans.clear();
		solve();
		printf("%u\n", ans.size());
		for(auto i:ans){
			printf("%u ", i.size());
			for(int j:i) printf("%d ", j);
			puts("");
		}
	}
	return 0;
}