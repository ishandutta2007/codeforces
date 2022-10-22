#include<bits/stdc++.h>
using namespace std;
vector<int> poss[26];
int main(){
	int i,no=0,las=INT_MAX;
	string s1,s2;cin>>s1>>s2;
	for(i=0;i<s1.size();i++)poss[s1[i]-'a'].push_back(i);
	for(i=0;i<s2.size();i++)if(poss[s2[i]-'a'].empty())return !(cout<<-1);
	for(i=0;i<s2.size();i++){
		vector<int> &v=poss[s2[i]-'a'];
		vector<int>::iterator ins=upper_bound(v.begin(),v.end(),las);
		if(ins==v.end())no++,las=v[0];
		else las=*ins;
	}
	cout<<no;
	return 0;
}
/*1
abc
xyz
*/
/*2
abcd
dabc
*/