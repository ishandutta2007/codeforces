#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,i;
	cin>>n>>i;
	i*=8;
	map<lli,lli> se;
	lli in;
	for(int i=0;i<n;i++){
		cin>>in;
		se[in]+=1;
	}
	lli numremove=((lli)se.size())-pow(2,i/n);
	vector<lli> am;
	lli prefixsum[se.size()]={};
	for(auto x:se){
		am.push_back(x.second);
	}
	prefixsum[0]=am[0];
	for(int i=1;i<se.size();i++){
		prefixsum[i]=am[i]+prefixsum[i-1];
	}
	lli ans=LLONG_MAX;
	for(lli i=0;i<=numremove;i++){
		ans=min(ans,(i-1>=0?prefixsum[i-1]:0)+(prefixsum[se.size()-1]-prefixsum[(lli)se.size()-(numremove-i)-1]));
	}
	if(ans==LLONG_MAX)ans=0;
	printf("%lli\n",ans);
	return 0;
}