#include <cstdio>

using namespace std;

int main()
{
	int a,b,c,d,t1,t2;

	scanf("%d%d%d%d",&a,&b,&c,&d);

	t1 = b * ((a-1)/c+1);

	for(t2=1;;t2++){
		if(t2/b*c + (t2-d)/b*c >= a) break;
	}

	if(t1>t2) printf("YES\n");
	else printf("NO\n");

	return 0;
}