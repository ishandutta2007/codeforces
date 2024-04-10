#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
set <int> indexs[MAXN];
int a[MAXN],b[MAXN];
int n;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		indexs[a[i]].insert(i);
		b[i]=a[i];
	}
	sort(b+0,b+n);
	int sz = n;
	long long ans = n;
	int now = 0;
	for (int i=0;i<n;i++){
		int nowNum = b[i];
		set<int>::iterator it = indexs[nowNum].lower_bound(now);
		if (it==indexs[nowNum].end()){
			ans+=sz;
			now = 0;
			it = indexs[nowNum].lower_bound(now);
		}
		now = *it;
		indexs[nowNum].erase(it);
		sz--;
	}
	cout<<ans<<endl;
	return 0;
}