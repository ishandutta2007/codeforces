#include<bits/stdc++.h>
using namespace std;
int a[4][200003],n,m,k;
bitset<200003>x[4],ans;
map<char,int>mp;
int main(){
	string s,t;
	mp['A']=0;mp['C']=1;
	mp['G']=2;mp['T']=3;
	cin>>n>>m>>k>>s>>t;
	for(int i=0;i<n;i++){
		a[mp[s[i]]][max(0,i-k)]++;
		a[mp[s[i]]][min(n,i+k+1)]--;
		ans[i]=1;
	}
	for(int i=0;i<4;i++)
		for(int j=1;j<n;j++)
			a[i][j]+=a[i][j-1];
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			if(a[i][j])
				x[i][j]=1;
	for(int i=0;i<m;i++)
		ans&=(x[mp[t[i]]]>>i);
	cout<<ans.count();
}