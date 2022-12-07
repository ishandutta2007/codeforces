#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
set<string> st;
int main() {
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char t[101];
		scanf("%s", t);
		string s = t;
		if (st.find(s) == st.end())
		{
			puts("NO");
			st.insert(s);
		}
		else puts("YES");
	}
}