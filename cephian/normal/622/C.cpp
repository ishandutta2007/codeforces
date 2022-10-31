#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;
int n,m;
int arr[N];
int smin[4*N],smax[4*N],l[4*N],r[4*N];

int rmx(int i, int j) {
	if(i == 0) return j;
	if(j == 0) return i;
	if(arr[i] > arr[j]) return i;
	return j;
}

int rmn(int i, int j) {
	if(i == 0) return j;
	if(j == 0) return i;
	if(arr[i] < arr[j]) return i;
	return j;
}

void build(int v, int i, int j) {
	l[v] = i;
	r[v] = j;
	if(i == j) {
		smin[v] = smax[v] = i;
	} else {
		build(v*2,i,(i+j)/2);
		build(v*2+1,(i+j)/2+1,j);
		smin[v] = rmn(smin[v*2], smin[v*2+1]);
		smax[v] = rmx(smax[v*2], smax[v*2+1]);
	}
}

int mn(int v, int i, int j) {
	if(i > r[v] || j < l[v]) return 0;
	if(i <= l[v] && j >= r[v]) return smin[v];
	return rmn(mn(v*2,i,j),mn(v*2+1,i,j));
}

int mx(int v, int i, int j) {
	if(i > r[v] || j < l[v]) return 0;
	if(i <= l[v] && j >= r[v]) return smax[v];
	return rmx(mx(v*2,i,j),mx(v*2+1,i,j));
}

int main() {
	ios::sync_with_stdio(0);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);
	build(1,1,n);
	while(m--) {
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		int mnp = mn(1,l,r);
		int mxp = mx(1,l,r);
		if(arr[mnp] != x) {
			printf("%d\n",mnp);
		} else if(arr[mxp] != x) {
			printf("%d\n",mxp);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}