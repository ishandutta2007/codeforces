#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <tr1/unordered_map>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
// cf IO: I64d
// atcoder IO: 
const int Maxn=1000005;
const long long mod=1e12+7;
const LL mul=Maxn+2;
vector<int> G[Maxn];
long long mm[Maxn];
LL hash[Maxn];
LL hash2[Maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	mm[0]=1;
	for (int i=1;i<Maxn;i++) mm[i]=mm[i-1]*mul;
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i=1;i<=n;i++){
		LL &hv=hash[i];
		sort(G[i].begin(),G[i].end());
		for (int j=0;j<G[i].size();j++){
			hv+=mm[G[i][j]];
		}
		hash2[i]=hash[i]+mm[i];
	//	cout<<hash[i]<<' '<<hash2[i]<<endl;
	}
	sort(hash+1,1+hash+n);
	sort(hash2+1,1+hash2+n);
	LL ncnt=1;
	LL ans=0;
	for (int i=2;i<=n;i++){
		if (hash[i]==hash[i-1]){
			ncnt++;
		}
		else{
			ans+=(LL)ncnt*(ncnt-1)/2;
			ncnt=1;
		}
	}
	ans+=(LL)ncnt*(ncnt-1)/2;
	//cout<<ans<<endl;
	ncnt=1;
	for (int i=2;i<=n;i++){
		if (hash2[i]==hash2[i-1]){
			ncnt++;
		}
		else{
			ans+=(LL)ncnt*(ncnt-1)/2;
			ncnt=1;
		}
	}
	//cout<<ncnt<<endl;
	ans+=(LL)ncnt*(ncnt-1)/2;
	printf("%I64d\n",ans);
	return 0;
}