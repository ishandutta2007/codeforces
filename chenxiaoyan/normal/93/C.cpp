#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back()
int n;
vector<int> v;
vector<string> ans;
string ex(int x){return (string)"e"+(char)('a'+x)+"x";}
string tos(int x){return (string)""+(char)(x+48);}
bool dfs(int rst){
	int i,j;
	if(!rst)return find(v.begin(),v.end(),n)<v.end();
	for(i=2;i<=8;i<<=1)for(j=0;j<v.size();j++)
		if(i*v[j]<=n){
			v.pb(i*v[j]);
			ans.pb((string)"lea "+ex(v.size()-1)+", ["+tos(i)+"*"+ex(j)+"]\n");
			if(dfs(rst-1))return true;
			v.ppb;ans.ppb;
		}
	for(i=1;i<=8;i<<=1)for(j=0;j<v.size();j++)for(int k=i==1?j:0;k<v.size();k++)
		if(v[j]+i*v[k]<=n){
			v.pb(v[j]+i*v[k]);
			ans.pb((string)"lea "+ex(v.size()-1)+", ["+ex(j)+" + "+tos(i)+"*"+ex(k)+"]\n");
			if(dfs(rst-1))return true;
			v.ppb;ans.ppb;
		}
	return false;
}
int main(){
	cin>>n;
	v.pb(1);
	for(int i=0;;i++)if(dfs(i)){
		cout<<i<<"\n";
		for(int j=0;j<ans.size();j++)cout<<ans[j];
		return 0;
	}
}
/*1
41
*/
/*2
2
*/
/*3
4
*/