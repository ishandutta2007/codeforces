/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m,mex,num;
map<int,int>mp;
vector<pair<int,int> >v;
void mina(){
	scanf("%d%d",&n,&m),m=min(m,n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),mp[x]++;
	mex=0;for(int i=0;mex<n;){
		if(mp.find(mex)!=mp.end()){mex++;continue;}
		if(i==m)break;
		i++,mex++;
	}
	for(auto it=mp.rbegin();it!=mp.rend();it++)if(it->first<=mex)break;else v.emplace_back(it->second,it->first);
	sort(v.begin(),v.end());
	int i=0;
	for(auto x:v){
		if(!m)break;
		while(m&&x.first){
			m--,x.first--,mp[x.second]--;
			while(mp.find(i)!=mp.end())i++;
			mp[i++]++;
		}
	}
	for(auto it=mp.begin();it!=mp.end();)if(!it->second)it=mp.erase(it);else it++;
	v.clear();
	int j=0;
	while(m--){
		while(mp.find(i)!=mp.end())i++;
		if(i==mex)break;
		while(mp.find(j)==mp.end()||mp[j]==1)j++;
		mp[j]--,mp[i]++;
	}
	printf("%d\n",mp.size()-mex);
	mp.clear(),v.clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}