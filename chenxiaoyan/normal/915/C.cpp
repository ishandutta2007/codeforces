/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int V1_SIZE=19;
int a,b;
vector<int> v1,v2;
bool vis[V1_SIZE];
signed main(){
	cin>>a>>b;
	while(a)v1.pb(a%10),a/=10;sort(v1.begin(),v1.end(),greater<int>());
	while(b)v2.pb(b%10),b/=10;reverse(v2.begin(),v2.end());
	if(v1.size()<v2.size()){
		for(int i=0;i<v1.size();i++)cout<<v1[i];
		return 0;
	}
	vector<int> ans;
	for(int i=-1;i<v1.size();i++){
		multiset<int,greater<int> > s;
		vector<int> v;
		for(int j=0;j<v1.size();j++)s.insert(v1[j]);
		bool ok=true;
		for(int j=0;j<=i;j++){
			if(s.find(v2[j])==s.end()){ok=false;break;}
			v.pb(v2[j]);
			s.erase(s.find(v2[j]));
		}
		if(!ok)continue;
		if(i<v1.size()-1){
			if(s.upper_bound(v2[i+1])==s.end())continue;
			v.pb(*s.upper_bound(v2[i+1]));
			s.erase(s.upper_bound(v2[i+1]));
		}
		for(int j=i+2;j<v1.size();j++)v.pb(*s.begin()),s.erase(s.begin());
		ans=max(ans,v);
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i];
	return 0;
}
/*1
123
222
*/
/*2
3921
10000
*/
/*3
4940
5000
*/
/*4
23923472834
23589234723
*/