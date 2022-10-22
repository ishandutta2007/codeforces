#include <bits/stdc++.h>	
using namespace std;
#define mkp make_pair
int n,sx,sy,ans;
int x[200004],y[200003];
vector<int> v1,v2;
int main(){	
	cin>>n>>sx>>sy;
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i],v1.push_back(x[i]),v2.push_back(y[i]);
	sort (v1.begin(),v1.end());
	sort (v2.begin(),v2.end());
	int t1=lower_bound(v1.begin(),v1.end(),sx)-v1.begin();
	int t2=upper_bound(v1.begin(),v1.end(),sx)-v1.begin(); 
	ans=max(t1,n-t2);
	t1=lower_bound(v2.begin(),v2.end(),sy)-v2.begin();
	t2=upper_bound(v2.begin(),v2.end(),sy)-v2.begin();
	ans=max(ans,max(t1,n-t2));
	cout<<ans<<"\n";
	if (ans==t1){
		cout<<sx<<" "<<sy-1;return 0;
	}
	if (ans==n-t2){
		cout<<sx<<" "<<sy+1;return 0;
	}
	if (ans==lower_bound(v1.begin(),v1.end(),sx)-v1.begin()){
		cout<<sx-1<<" "<<sy;return 0;
	}
	cout<<sx+1<<" "<<sy;return 0;
}