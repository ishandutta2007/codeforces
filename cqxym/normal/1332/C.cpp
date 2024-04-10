#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define I inline
int f[200001];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
I void Merge(int x,int y){
	if(GetF(x)!=GetF(y)){
		f[f[x]]=f[y];
	}
}
vector<char>G[200001];
I void Solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ct[26],ans=0;
	for(R i=1;i<=n;i++){
		f[i]=i;
		G[i].clear();
	}
	for(R i=0;i!=k;i++){
		for(R j=i+k+1;j<=n;j+=k){
			Merge(j-k,j);
		}
	}
	for(R i=0;i!=n;i++){
		Merge(i+1,n-i);
	}
	for(R i=1;i<=n;i++){
		G[GetF(i)].push_back(s[i-1]);
	}
	for(R i=1;i<=n;i++){
		if(GetF(i)==i){
			for(R j=0;j!=26;j++){
				ct[j]=0;
			}
			for(R j=0;j!=G[i].size();j++){
				ct[G[i][j]-'a']++;
			}
			int mx=0;
			for(R j=0;j!=26;j++){
				if(ct[j]>mx){
					mx=ct[j];
				}
			}
			ans+=G[i].size()-mx;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}