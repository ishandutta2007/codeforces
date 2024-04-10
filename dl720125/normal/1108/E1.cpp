#include <bits/stdc++.h>
//#define int long long
using namespace std;

int n,m,maxv=-1,a[310],l[310],r[310],cnt;
vector<int> h(310);

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(i!=j){
			int val=a[i]-a[j];
			vector<int> ans; 
			for(int k=1;k<=m;k++){
				if(l[k]<=j&&j<=r[k]&&(i<l[k]||i>r[k])){
					val++;
					ans.push_back(k);
				}
			}
			if(val>maxv){
				maxv=val;
				cnt=ans.size();
				for(int i=0;i<cnt;i++) h[i]=ans[i];
			}
		}
	}
	if(maxv==-1) maxv=0;
	cout<<maxv<<endl;
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++) cout<<h[i]<<" ";
	cout<<endl;
	return 0;
}