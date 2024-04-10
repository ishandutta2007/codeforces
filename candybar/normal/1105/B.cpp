#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char s[maxn];
int n,k;
int calc(char c){
	int num = 0, ans = 0;
	for(int i=1;i<=n+1;i++){
		if(s[i] == c) num++;
		else{
			ans += num / k;
			num = 0;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s + 1);
	s[n + 1] = '#';
	int ans = 0;
	for(char i='a';i<='z';i++) ans = max(ans,calc(i));
	printf("%d\n",ans);
	return 0;
}