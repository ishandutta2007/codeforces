#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	double ret=a;
	for(int i=a-1;i>=1;i--)
	{
		ret-=pow(double(i)/double(a),b);
	}
	printf("%.10lf\n",ret);
}