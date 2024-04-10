#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e6+5;
int a[N],n,dist[N]={};
ll fsum[N]={};
int last[N];

int main() {	
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	fill(last,last+N,N);
	double ans = 0;
	for(int i = n-1; i >= 0; --i) {
		dist[i] = dist[i+1];
		fsum[i] = fsum[i+1] + dist[i+1];
		if(last[a[i]] == N) ++dist[i];
		else fsum[i] -= last[a[i]]-i;
		last[a[i]] = i;
		ans += 2*(double(dist[i])*(n-i) - fsum[i]) - 1;
	}
	ans /= double(n)*n;
	printf("%.12lf\n",ans);
}