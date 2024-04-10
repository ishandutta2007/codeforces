#include<cstdio>
int n,a;double s;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a),s+=a;
	s/=n;
	printf("%lf",s);
	return 0;
}