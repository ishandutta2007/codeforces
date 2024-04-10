#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAXN 110
#define INF (1ll<<50)
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N;
LL D;
LL a[MAXN];
LL x[MAXN], y[MAXN];

LL dd[MAXN];
bool used[MAXN];

inline ULL dist(int i, int j){
	return fabs(x[i]-x[j])+fabs(y[i]-y[j]);
}

int main(){
	cin >> N >> D;
	for(int i=2;i<=N-1;i++)cin >> a[i];
	for(int i=1;i<=N;i++)cin >> x[i] >> y[i];
	for(int i=1;i<=N;i++)dd[i]=INF;
	dd[N]=0;
	priority_queue <pair <LL,int> > coda;
	coda.push(make_pair(0,N));
	while(!coda.empty()){
		int v=coda.top().second;
		coda.pop();
		if(used[v])continue;
		used[v]=1;
		for(int i=1;i<=N;i++){
			if(i==v)continue;
			LL xxx=dist(i,v)*D+dd[v]-a[i];
			if(xxx<dd[i]){
				dd[i]=xxx;
				coda.push(make_pair(-xxx,i));
			}
		}
	}
	cout << dd[1] << "\n";
}