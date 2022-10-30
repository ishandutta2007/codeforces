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

int x[105],y[105], ans = 0,a,b,n;

void go(int i, int j) {
	if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b)
		ans = max(ans,x[i]*y[i] + x[j] * y[j]);
}

int main() {	
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d",x+i,y+i);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			for(int pos = 0; pos < 4; ++pos) {
				go(i,j);
				swap(x[i],y[i]);
				go(i,j);
				swap(x[j],y[j]);
				go(i,j);
				swap(x[i],y[i]);
				go(i,j);
				swap(x[j],y[j]);
				swap(a,b);
				go(i,j);
				swap(x[i],y[i]);
				go(i,j);
				swap(x[j],y[j]);
				go(i,j);
				swap(x[i],y[i]);
				go(i,j);
				swap(x[j],y[j]);
				swap(a,b);
			}
		}
	}
	printf("%d\n",ans);
}