/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int A_I=200000;
vector<int> tim[A_I+1];
int main(){
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		int x;
		cin>>x;
		int las=-1;
		for(int i=2;i*i<=x;i++){
			int cnt=0;
			while(x%i==0)las=i,cnt++,x/=i;
			tim[i].push_back(cnt);
		}
		if(x>1){
			if(las==x)tim[las].back()++;
			else tim[x].push_back(1);
		}
	}
	long long ans=1;
	for(int i=1;i<=A_I;i++){
		vector<int> &v=tim[i];
		if(v.size()+2<=n)continue;
		if(v.size()+1==n){
			int mn=*min_element(v.begin(),v.end());
			while(mn--)ans*=i;
		}
		else{
			sort(v.begin(),v.end());
			for(int j=1;j<=v[1];j++)ans*=i;
		}
	}
	cout<<ans;
	return 0;
}