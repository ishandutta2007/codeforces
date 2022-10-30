#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
int cnt[26][26];
char s[maxn];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<n;i++){
		cnt[s[i-1]-'A'][s[i]-'A']++;
	}
	pair<int,int> ans = make_pair(0,0);
	for (int i=0;i<26;i++){
		for (int j=0;j<26;j++){
			if (cnt[i][j]>cnt[ans.first][ans.second]){
				ans = make_pair(i,j);
			}
		}
	}
	printf("%c%c\n",ans.first+'A',ans.second+'A');
	return 0;
}