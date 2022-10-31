#include<bits/stdc++.h>
using namespace std;
const int maxm = 2000;
vector<int > indexs;
int cnt[maxm];
int m,n;
char s[maxm];
char q[maxm][maxm];
int unknown[maxm];
int tq[maxm];
bool used[maxm];
int temp[maxm];
int sz;
void input(){
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		scanf("%s",&q[i]);
	}
}
void solve(){
	for (int i=0;i<n;i++){
		used[s[i]] = true;
	}
	for (int i=0;i<n;i++){
		if (s[i]=='*'){
			indexs.push_back(i);
			for (int j=0;j<m;j++){
				unknown[j]+=(used[q[j][i]]==false);
			}
		}
	}
	for (int i=0;i<n;i++){
		if (s[i]!='*'){
			for (int j=0;j<m;j++){
				if (q[j][i]!=s[i]){
					unknown[j]=0;
				}
			}
		}else{
			for (int j=0;j<m;j++){
				if (used[q[j][i]]){
					unknown[j]=0;
				}
			}
		}
	}
	for (int i=0;i<m;i++){
		if (unknown[i])tq[sz++] =i;
	}
	assert(sz!=0);
	for (int i=0;i<sz;i++){
		int x = tq[i];
		for (int index:indexs){
			char now = q[x][index];
			if ((!used[now])&&(cnt[now]==i))cnt[now]++;
		}
	}
	int ans =0;
	for (int i='a';i<='z';i++){
		if (cnt[i]==sz){
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	input();
	solve();
	return 0;
}