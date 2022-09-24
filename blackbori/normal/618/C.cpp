#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct xy{long long x,y,d;};

vector <xy> K;
long long n,i;

bool comp(xy ca,xy cb)
{
	if(ca.x != cb.x) return ca.x < cb.x;
	else return ca.y < cb.y;
}

int main()
{
	scanf("%I64d",&n);
	
	xy xx;
	
	for(i=0;i<n;i++){
		scanf("%I64d %I64d",&xx.x,&xx.y); xx.d=i+1;
		K.push_back(xx);
	}
	
	sort(K.begin(),K.end(),comp);
	
	printf("%I64d %I64d ",K[0].d,K[1].d);
	
	i=2;
	while(K[0].x==K[i].x || (K[0].x-K[1].x)*(K[1].y-K[i].y) == (K[1].x-K[i].x)*(K[0].y-K[1].y)) i++;
	
	printf("%I64d\n",K[i].d);
	
	return 0;
}