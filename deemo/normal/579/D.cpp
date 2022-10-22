#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int n, k, x;
vector<int>	vec, l, r;

ll get(int ind){
	ll ret = l[ind];
	ret |= r[ind + 1];
	ll t = vec[ind];
	for (int i = 0; i < k; i++)
		t *= x;
	return ret | t;
}	

int main(){
	scanf("%d%d%d", &n, &k, &x);
	vec.resize(n);
	l.resize(n + 2);
	r.resize(n + 2);

	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);

	l[0] = 0;
	r[n] = 0;
	for (int i = 1; i <= n; i++)
		l[i] = l[i - 1] | vec[i - 1];

	for (int i = n - 1; i >= 0; i--)
		r[i] = r[i + 1] | vec[i];

	ll maxi = 0;
	for (int i =0; i < n; i++)
		maxi = max(maxi, get(i));
	printf("%I64d\n", maxi);
	return 0;	
}