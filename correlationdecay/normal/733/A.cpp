#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#define maxn 1000009
using namespace std;
const int INF=1e9;
char s[maxn];
vector<int>a;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	a.push_back(0);
	for(int i=1;i<=n;i++){
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
			a.push_back(i);
	}
	a.push_back(n+1);
	int ans=0;
	for(int i=1;i<(int)a.size();i++)
		ans=max(ans,a[i]-a[i-1]);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}