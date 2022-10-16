#include<bits/stdc++.h>
using namespace std;
int T,n,m;
string c[50003];
int main(){
	cin>>T;
	cin.tie();
	while(T--){
		int ans1=2147483647,ans2=2147483647,k;
		cin>>n>>m;
		vector<int>v;
		for(int i=0;i<n;i++)
			cin>>c[i];
		for(int i=0;i<n;i++){
			int ccc=0;
			for(int j=0;j<m;j++)
				ccc+=(c[i][j]=='.');
			if(ans1>ccc)
				ans1=ccc;
		}
		for(int i=0;i<n;i++){
			int ccc=0;
			for(int j=0;j<m;j++)
				ccc+=(c[i][j]=='.');
			if(ans1==ccc)
				v.push_back(i);
		}
		for(int i=0;i<m;i++){
			int ccc=0;
			for(int j=0;j<n;j++)
				ccc+=(c[j][i]=='.');
			for(int j=0;j<v.size();j++)
				if(c[v[j]][i]=='.')
				{
					ccc--;
					break;
				}
			ans2=min(ccc,ans2);
		}
		cout<<ans1+ans2<<endl;
	}
}