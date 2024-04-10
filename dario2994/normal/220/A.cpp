#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tr1/unordered_map>
#define MAXN 100010
#define INF 1000000100
#define rp(i,n) for(int i=0;i<n;i++)
#define rp1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using namespace tr1;
typedef long long LL;
typedef unsigned long long ULL;

int n;
int a[MAXN];
int b[MAXN];
unordered_map <int,pair <int,int> > posti;

int main(){
	cin >> n;
	rp(i,n)cin >> a[i];
	rp(i,n)b[i]=a[i];
	sort(b,b+n);
	int u=0;
	while(u<n){
		int v=u;
		while(v<n and b[u]==b[v])v++;
		posti[b[u]]=make_pair(u,v-1);
		u=v;
	}
	//~ cout << posti[2].first << " " << posti[2].second;
	//~ return 0;
	vector <int> wrong;
	rp(i,n){
		if(posti[a[i]].first<=i and i<=posti[a[i]].second)continue;
		wrong.push_back(i);
	}
	if(wrong.size()==0)cout << "YES";
	if(wrong.size()>2) cout << "NO";
	if(wrong.size()==1)cout << "NO";
	if(wrong.size()==2)cout << "YES";
}