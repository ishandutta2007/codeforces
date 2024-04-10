#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define N 55000
vector<int>S[10],G[N];
int pos[10][52][2],pre[N],f[N];
bool vis[N];
inline int DP(int x){
	if(f[x]!=0){
		return f[x];
	}
	pre[x]=-1;
	for(int T:G[x]){
		int cur=DP(T);
		if(cur>f[x]){
			pre[x]=T;
			f[x]=cur;
		}
	}
	f[x]++;
	return f[x];
}
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		S[i].clear();
		string s;
		cin>>s;
		for(char T:s){
			S[i].push_back(T<'a'?T-'A':T-'a'+26);
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=52;j++){
			pos[i][j][0]=pos[i][j][1]=N;
		}
		int s=S[i].size();
		for(R j=0;j!=s;j++){
			int x=S[i][j];
			if(pos[i][x][0]==N){
				pos[i][x][0]=j;
			}else{
				pos[i][x][1]=j;
			}
		}
	}
	for(R i=0;i!=52;i++){
		for(R j=0;j!=1<<n;j++){
			bool tag=true;
			for(R k=0;k!=n;k++){
				if(pos[k][i][j>>k&1]==N){
					tag=false;
					break;
				}
			}
			int t=i<<n|j;
			vis[t]=tag;
			f[t]=0;
		}
	}
	for(R i=0;i!=52<<n;i++){
		vector<int>().swap(G[i]);
	}
	for(R i=0;i!=52;i++){
		for(R j=0;j!=1<<n;j++){
			int idx=i<<n|j;
			if(vis[idx]==true){
				for(R k=0;k!=52;k++){
					bool tag=true;
					int curS=0;
					for(R l=0;l!=n;l++){
						if(pos[l][k][0]==N){
							tag=false;
							break;
						}
						if(pos[l][i][j>>l&1]>=pos[l][k][0]){
							if(pos[l][k][1]==N||pos[l][i][j>>l&1]>=pos[l][k][1]){
								tag=false;
								break;
							}
							curS|=1<<l;
						}
					}
					if(tag==true){
						G[idx].push_back(k<<n|curS);
					}
				}
			}
		}
	}
	int ans=0,ansid;
	for(R i=0;i!=52<<n;i++){
		if(vis[i]==true){
			int cur=DP(i);
			if(cur>ans){
				ans=cur;
				ansid=i;
			}
		}
	}
	cout<<ans<<endl;
	if(ans!=0){
		for(R i=ansid;i!=-1;i=pre[i]){
			int x=i>>n;
			if(x<26){
				cout<<(char)(x+'A');
			}else{
				cout<<(char)(x-26+'a');
			}
		}
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}