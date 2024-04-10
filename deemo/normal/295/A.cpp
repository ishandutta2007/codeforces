#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;
#define Query pair<pair<int, int>, int>
#define left first.first
#define right first.second

const int max_n = 3e5 + 200;

int n, m, q;
vector<ll>	arr;
vector<Query>	vec;
vector<ll>	sum;
vector<int>	mark;

int main(){
	scanf("%d%d%d", &n, &m, &q);
	arr.resize(n);
	sum.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &arr[i]);
	
	vec.resize(m);
	mark.resize(m);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &vec[i].left, &vec[i].right, &vec[i].second);
		vec[i].left--;
	}
	while(q--){
		int l, r;	scanf("%d%d", &l, &r);	l--;
		mark[l]++;
		if (r != m)	mark[r]--;
	}
	
	ll c = 0;
	for (int i = 0; i < m; i++){
		c += mark[i];
		sum[vec[i].left] += c * vec[i].second;
		if (vec[i].right != n)
			sum[vec[i].right] -= c * vec[i].second;
	}
	
	c = 0;
	for (int i = 0; i < n; i++){
		c += sum[i];
		arr[i] += c;
		printf("%I64d ", arr[i]);
	}
	printf("\n");
	return 0;
}