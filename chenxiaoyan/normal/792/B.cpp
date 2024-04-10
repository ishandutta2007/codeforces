/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m;
vector<int> v;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)v.pb(i);
	int now=0;
	while(m--){
		int x;
		cin>>x;
		int now0=(now+x)%v.size();
		now=now0%(v.size()-1);
		cout<<v[now0]<<" ";
		v.erase(v.begin()+now0);
	}
	return 0;
}