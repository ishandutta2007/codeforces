using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 500005
int n;
int v[N];
struct cmp{bool operator()(int a,int b){return v[a]>v[b] || v[a]==v[b] && a<b;}};
multiset<int,cmp> s;
int main(){
//	freopen("in.txt","r",stdin);
	int Q;
	scanf("%d",&Q);
	int i=1;
	while (Q--){
		int op;
		scanf("%d",&op);
		if (op==1){
			++n;
			scanf("%d",&v[n]);			
			s.insert(n);
		}
		else if (op==2){
			for (;i<=n;++i)
				if (v[i]!=-1){
					s.erase(i);
					v[i]=-1;
					printf("%d ",i);
					break;
				}
		}
		else{
			int x=*s.begin();
			printf("%d ",x);
			s.erase(x);
			v[x]=-1;
		}
	}
	return 0;	
}