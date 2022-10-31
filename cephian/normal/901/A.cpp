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

const int N = 1e5+5;
int d[N],st[N] = {}, ed[N] = {};

int main() {	
	int h;
	scanf("%d",&h);
	for(int i = 0; i <= h; ++i) {
		scanf("%d",d+i);
	}
	st[0] = 1, ed[0] = d[0];
	for(int i = 1; i <= h; ++i) {
		st[i] = st[i-1] + d[i-1];
		ed[i] = ed[i-1] + d[i];
	}

	bool perfect = true;
	for(int i = 0; i < h; ++i) {
		if(d[i] > 1 && d[i+1] > 1) {
			perfect = false;
			break;
		}
	}
	if(perfect) {
		printf("perfect\n");
		return 0;
	}

	printf("ambiguous\n");
	for(int i = 0; i <= h; ++i) {
		if(i == 0) {
			printf("0 ");
		} else {
			for(int k = st[i]; k <= ed[i]; ++k) {
				printf("%d ", st[i-1]);
			}
		}
	}
	printf("\n");

	for(int i = 0; i <= h; ++i) {
		if(i == 0) {
			printf("0 ");
		} else {
			printf("%d ",st[i-1]);
			for(int k = st[i]+1; k <= ed[i]; ++k) {
				printf("%d ", ed[i-1]);
			}
		}
	}
	printf("\n");
}