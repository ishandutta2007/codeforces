#include<stdio.h>
#include<algorithm>
using namespace std;
int a[300005];
int main()
{
	int n,m;
    long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
	scanf("%d",&a[i]);
	sum+=a[i];
	}
	sort(a,a+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
	int temp;
	scanf("%d",&temp);
	int reduce=a[n-temp];
	printf("%lld\n",sum-reduce);
    }
    return 0;
}