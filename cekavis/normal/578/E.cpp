#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;

int ans, nxt[N];
char s[N];
vector<int> f[4];
void work(vector<int> x){
	for(int i:f[x[0]]) for(int j=i; j; j=nxt[j]) printf("%d ", j);
	for(int i=0; i<(int)f[x[1]].size(); ++i){
		for(int j=f[x[1]][i]; j; j=nxt[j]) printf("%d ", j);
		if(i<(int)f[x[2]].size())
			for(int j=f[x[2]][i]; j; j=nxt[j]) printf("%d ", j);
	}
	for(int i:f[x[3]]) for(int j=i; j; j=nxt[j]) printf("%d ", j);
}
int main() {
	scanf("%s", s+1);
	for(int i=strlen(s+1); i; --i)
		if(s[i]=='L')
			if(!f[2].empty())
				nxt[i]=f[2].back(), f[2].pop_back(), f[1].push_back(i);
			else if(!f[0].empty())
				nxt[i]=f[0].back(), f[0].pop_back(), f[3].push_back(i);
			else f[1].push_back(i), ++ans;
		else
			if(!f[3].empty())
				nxt[i]=f[3].back(), f[3].pop_back(), f[0].push_back(i);
			else if(!f[1].empty())
				nxt[i]=f[1].back(), f[1].pop_back(), f[2].push_back(i);
			else f[0].push_back(i), ++ans;
	// printf(">> %d %d %d %d\n", (int)f[0].size(), (int)f[1].size(), (int)f[2].size(), (int)f[3].size());
	printf("%d\n", ans-1);
	if(f[0].size()<f[1].size()) work({3, 1, 0, 2});
	else if(f[1].size()<f[0].size()) work({2, 0, 1, 3});
	else if(f[0].empty()) work({2, 0, 1, 3});
	else{
		for(int i:f[2]) for(int j=i; j; j=nxt[j]) printf("%d ", j);
		for(int i=0; i<(int)f[0].size(); ++i){
			if(i<(int)f[0].size())
				for(int j=f[0][i]; j; j=nxt[j]) printf("%d ", j);
			if(!i) for(int i:f[3]) for(int j=i; j; j=nxt[j]) printf("%d ", j);
			for(int j=f[1][i]; j; j=nxt[j]) printf("%d ", j);
		}
	}
	return 0;
}