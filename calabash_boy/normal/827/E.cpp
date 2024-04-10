#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
map<int,int> mp;
char s [MAXN];
int n,k;
bool can [MAXN];
bool check(int length){
	for (int i = 1;i<=length;i++){
		char who = s[i];
		int now = i+length;
		while (now<=n){
			if (who!='?'&&s[now]!='?'&&who!=s[now])return false;
			if (s[now]!='?') who = s[now];
			now+=length;
		}
	}
	return true;
}
int main(){
	scanf("%d",&k);
	while (k--){
		scanf("%d%s",&n,s+1);
		int sum = 0;
		memset (can,false,sizeof(bool)*(n+2));
		mp.clear();
		for(int i = 1; i <=n; ++ i) mp[s[i]] = 1;
		if(mp['V'] + mp['K'] <= 1){
			printf("%d\n", n);
			for(int i = 1; i <= n; ++ i) printf("%d%c", i, i == n ? '\n' : ' ');
			continue;
		}
		for (int i=2;i<=n;i++){
			if (can[i]){
				continue;
			}else if (check(i)){
				for (int j=i;j<=n;j+=i){
					can[j]=true;
				}
			}
		}
		for (int i=2;i<=n;i++){
			sum+=can[i];
		}
		printf("%d\n",sum);
		for (int i=1;i<=n;i++){
			if (can[i]){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}