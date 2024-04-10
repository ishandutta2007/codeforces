#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e6+5;
vi st;
int x[N],n,l;
bool fix[N]={0};

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",x+i);
	}
	scanf("%d",&l);
	while(l--) {
		int a;
		scanf("%d",&a);
		fix[a-1] = true;
	}
	for(int i = n-1; i >= 0; --i) {
		if(st.empty() || fix[i] || st.back() != x[i]) {
			st.push_back(x[i]);
			x[i] = -x[i];
		} else {
			st.pop_back();
		}
	}
	if(!st.empty()) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for(int i = 0; i < n; ++i) {
			printf("%d ",x[i]);
		}
		printf("\n");
	}
	return 0;
}