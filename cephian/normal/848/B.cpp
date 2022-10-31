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
int pos[N],del[N],grp[N],sol[N];
int n,w,h;

unordered_map<int,vi> ind;
unordered_set<int> all;


int main() {	
	scanf("%d%d%d",&n,&w,&h);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d",grp+i,pos+i,del+i);
		--grp[i];
		ind[del[i]-pos[i]].push_back(i);
		all.insert(del[i]-pos[i]);
	}
	for(int c : all) {
		vector<int> A[2];
		vector<int> B,C;
		for(int i : ind[c])
			A[grp[i]].emplace_back(i);
		for(int k = 0; k < 2; ++k)
			sort(A[k].begin(),A[k].end(),[=](int i, int j){return pos[i] < pos[j];});
		reverse(A[0].begin(),A[0].end());
		for(int k = 0; k < 2; ++k) {
			for(int a : A[k])
				B.push_back(a);
			for(int a : A[!k])
				C.push_back(a);
		}
		for(int i = 0; i < B.size(); ++i)
			sol[B[i]] = C[i];
	}
	for(int i = 0; i < n; ++i) {
		if(grp[sol[i]] == 0) {
			printf("%d %d\n",pos[sol[i]],h);
		} else {
			printf("%d %d\n",w,pos[sol[i]]);
		}
	}
}