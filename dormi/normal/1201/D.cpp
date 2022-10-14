#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef pair<lli, lli> pll;
lli MAXAM=4e13;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,m,k,q;
	cin>>n>>m>>k>>q;
	map<lli,vector<lli>> treasure;
	lli a,b;
	lli high=0;
	vector<lli> los;
	for(lli i=0;i<k;i++){
		cin>>a>>b;
		high=max(high,a);
		if(a==1){
			los.push_back(b);
		}
		else{
			treasure[a].push_back(b);
		}
	}
	vector<lli> safe;
	lli in;
	for(lli i=0;i<q;i++){
		cin>>in;
		safe.push_back(in);
	}
	sort(safe.begin(),safe.end());
	lli leftbest=0;
	lli leftindex=1;
	lli rightbest=0;
	lli rightindex=1;
	if(los.size()){
		sort(los.begin(),los.end());
		lli teleftindex=los[0];
		lli terightindex=los.back();
		leftbest=terightindex-1+(terightindex-teleftindex);
		rightbest=terightindex-1;
		leftindex=teleftindex;
		rightindex=terightindex;
	}
	for(auto x:treasure){
		sort(x.second.begin(),x.second.end());
		lli teleftindex=x.second[0];
		lli terightindex=x.second.back();
		lli teleftbest=LLONG_MAX;
		lli terightbest=LLONG_MAX;
		auto te=upper_bound(safe.begin(),safe.end(),leftindex);
		if(te!=safe.end()){
			lli loc=te-safe.begin();
			teleftbest=min(teleftbest,leftbest+safe[loc]-leftindex+(abs(terightindex-safe[loc])+(terightindex-teleftindex)));
			terightbest=min(terightbest,leftbest+safe[loc]-leftindex+(abs(teleftindex-safe[loc])+(terightindex-teleftindex)));
		}
		if(te!=safe.begin()){
			lli loc=te-safe.begin();
			loc-=1;
			teleftbest=min(teleftbest,leftbest+leftindex-safe[loc]+(abs(terightindex-safe[loc])+(terightindex-teleftindex)));
			terightbest=min(terightbest,leftbest+leftindex-safe[loc]+(abs(teleftindex-safe[loc])+(terightindex-teleftindex)));
		}
		te=upper_bound(safe.begin(),safe.end(),rightindex);
		if(te!=safe.end()){
			lli loc=te-safe.begin();
			teleftbest=min(teleftbest,rightbest+safe[loc]-rightindex+(abs(terightindex-safe[loc])+(terightindex-teleftindex)));
			terightbest=min(terightbest,rightbest+safe[loc]-rightindex+(abs(teleftindex-safe[loc])+(terightindex-teleftindex)));
		}
		if(te!=safe.begin()){
			lli loc=te-safe.begin();
			loc-=1;
			teleftbest=min(teleftbest,rightbest+rightindex-safe[loc]+(abs(terightindex-safe[loc])+(terightindex-teleftindex)));
			terightbest=min(terightbest,rightbest+rightindex-safe[loc]+(abs(teleftindex-safe[loc])+(terightindex-teleftindex)));
		}
		leftindex=teleftindex;
		leftbest=teleftbest;
		rightindex=terightindex;
		rightbest=terightbest;
	}
	printf("%lli\n",min(leftbest,rightbest)+high-1);
	return 0;
}