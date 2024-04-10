/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
int n;
void mian(){
	cin>>n;
	vector<int> po,ne;
	int ans=-inf;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>0)po.pb(x);
		if(x==0)ans=0;
		if(x<0)ne.pb(x);
	}
	sort(po.begin(),po.end(),greater<int>());
	sort(ne.begin(),ne.end());
	for(int i=0;i<=5;i++){
		if(i<=po.size()&&5-i<=ne.size()){
			int res=1;
			if(5-i&1){
				for(int j=(int)(po.size())-1;j>=(int)(po.size())-i;j--)res*=po[j];
				for(int k=(int)(ne.size())-1;k>=(int)(ne.size())-(5-i);k--)res*=ne[k];
			}
			else{
				for(int j=0;j<i;j++)res*=po[j];
				for(int k=0;k<5-i;k++)res*=ne[k];
			}
			ans=max(ans,res);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}