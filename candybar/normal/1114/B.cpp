#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[maxn],b[maxn];
bool del[maxn];
bool cmp(const int &x,const int &y){
	return a[x] < a[y];
}
vector <int> p;
ll sum;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		b[i] = i;
		sum += a[i];
	}
	sort(b + 1,b + n + 1,cmp);
	int lef = n - m * k;
	for(int i = 1;i <= lef;i++){
		del[b[i]] = true;
		sum -= a[b[i]];
	}
	printf("%I64d\n",sum);
	int j = 0,cnt = 0;
	for(int i = 1;i < k;i++){
		while(cnt < m){
			j++;
			if(!del[j]) cnt++;
		}
		printf("%d%c",j,i == k - 1 ? '\n' : ' ');
		cnt = 0;
	}
	return 0;
}