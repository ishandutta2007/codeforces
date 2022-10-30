
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e9+100;
typedef long long LL;
set<int> sq;
char s[15];
bool used[15];
int n;
int ans=100;
void check(){
	for (int i=0;i<n;i++){
		if (used[i]){
			if (s[i]=='0')return;
			else{
			break;
		}
		}
	}
	int temp =0;
	int cnt=0;
	for (int i=0;i<n;i++){
		if (used[i]){
			cnt++;
			temp = temp*10+s[i]-'0';
		}
	}
	if (sq.count(temp)){
		ans = min(ans,n-cnt);
	}
}
void dfs(int dep){
	if (dep==n){
		check();
		return;
	}
	dfs(dep+1);
	used[dep]=1;
	dfs(dep+1);
	used[dep]=0;
}
int main(){
	scanf("%s",s);
	n = strlen(s);
	for (LL i=1;i*i<maxn;i++){
		sq.insert(i*i);
	}
	dfs(0);
	if (ans!=100)
	cout<<ans<<endl;
	else
	cout<<-1<<endl;
	return 0;
}