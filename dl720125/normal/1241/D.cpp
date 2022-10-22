#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int n,a[300010],l[300010],r[300010];
map<int,int> mp,pm;
vector<int> v[300010];

signed main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		mp.clear();pm.clear();
		for(int i=1;i<=n;i++){cin>>a[i];mp[a[i]]=1;}
		int cnt=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;
			pm[it->first]=cnt;
		}
		for(int i=1;i<=n;i++) a[i]=pm[a[i]];
		for(int i=1;i<=n;i++) v[a[i]].clear();
		for(int i=1;i<=n;i++){
			v[a[i]].push_back(i);
		}
		for(int i=1;i<=cnt;i++){
			l[i]=v[i][0];
			r[i]=v[i].back();
		}
		int maxv=1,cur=1,prel=l[1],prer=r[1];
		for(int i=2;i<=cnt;i++){
			if(l[i]>prer){
				cur++;
				prel=l[i];
				prer=r[i];
			}
			else{
				maxv=max(maxv,cur);
				cur=1;
				prel=l[i];
				prer=r[i];
			}
		}
		maxv=max(maxv,cur);
		cout<<cnt-maxv<<endl;
	}
	return 0;
}