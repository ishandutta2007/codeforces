#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1<<9|5;
typedef long long ll;
vector<pair<int,int> > t;
ll a[MAX_N][MAX_N],b[MAX_N][MAX_N];
int n;
inline int mo(int x){ return x>=n?x-n:x; }
int main(){
	int k; scanf("%d",&k);
	n=1<<k;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) 
			scanf("%lld",&a[i][j]);
	int top; scanf("%d",&top);
	for(int i=0;i<top;++i){
		int x,y; scanf("%d%d",&x,&y);
		t.push_back(make_pair(x,y));
	}
	for(int i=(int)t.size()-1;i>=0;--i){
		t[i].first=mo(t[i].first+n-t[0].first);
		t[i].second=mo(t[i].second+n-t[0].second);
//		printf("(%d %d)",t[i].first,t[i].second);
	}
	for(int cnt=1;cnt<=k;++cnt){
		memset(b,0,sizeof(b));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(auto s:t)
					b[mo(i+s.first)][mo(j+s.second)]^=a[i][j];
		memcpy(a,b,sizeof(a));
		for(int i=0;i<t.size();++i){
			t[i].first=mo(t[i].first+t[i].first);
			t[i].second=mo(t[i].second+t[i].second);
		}
	}
	int ret=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(a[i][j]>0) ++ret;
	printf("%d\n",ret);
	return 0;
}