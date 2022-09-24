#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int n,i,sa,sb,sp,_sa,_sb,_sp,s;
int D[111];

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",D+i);
	D[n] = 0;
	
	for(i=0;i<=n;i++){
		if(D[i]==0){
			s += max(sp,max(sa,sb));
			sa=sb=sp=0;
		}
		else{
			if(D[i] == 1) _sa = max(sp,sb)+1, _sb=0;
			else if(D[i] == 2) _sb = max(sp,sa)+1, _sa=0;
			else _sa = max(sp,sb)+1, _sb = max(sp,sa)+1;
			_sp = max(sa,sb);
			sa=_sa, sb=_sb; sp=_sp;
		}
	}
	
	printf("%d\n",n-s);
	
	return 0;
}