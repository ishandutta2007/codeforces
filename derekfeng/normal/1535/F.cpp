#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,pre,N;
string s,t;
ll ans;
map<string,vector<string> >S;
map<string,bool>vis;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;t=s;
		sort(t.begin(),t.end());
		S[t].push_back(s);
	}
	m=s.size();
	for(auto it:S){
		vector<string> v=it.second;
		N=v.size(),ans+=1337ll*pre*N,pre+=N;
		if(N<=200*m){
			for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
				int L=0,R=m-1;
				while(v[i][L]==v[j][L]&&L<=R)L++;
				while(v[i][R]==v[j][R]&&L<=R)R--;
				bool f1=1,f2=1;
				for(int k=L;k<R;k++)f1&=(v[i][k]<=v[i][k+1]),f2&=(v[j][k]<=v[j][k+1]);
				ans+=2;
				if(f1||f2)ans--;
			}
		}else{
			ll cur=(ll)N*(N-1);
			vis.clear();
			for(auto s:v)vis[s]=1;
			for(auto s:v)for(int i=0;i<m;i++)for(int j=i+2;j<=m;j++){
				t=s,sort(t.begin()+i,t.begin()+j);
				if(t[i]!=s[i]&&t[j-1]!=s[j-1]&&vis.count(t))cur--;
			}
			ans+=cur;
		}
	}
	cout<<ans;
}