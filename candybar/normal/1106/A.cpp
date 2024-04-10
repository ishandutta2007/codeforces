#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 505
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char s[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i] + 1);
	int ans = 0;
	for(int i=2;i<n;i++){
		for(int j=2;j<n;j++){
			ans += (s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 1][j + 1] == 'X' && s[i][j] == 'X');
		}
	}
	printf("%d\n",ans);
	return 0;
}