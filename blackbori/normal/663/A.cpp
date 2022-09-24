#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector <int> P,M;

int F[1010],K[3],n;

int main()
{
	int i=0,s=0,a,b,c,d,k;
	bool ff=1;
	char t;
	
	while(true){
		scanf("%c",&t);
		if(t=='-') ff=0;
		else if (t=='+') ff=1;
		else if(t=='?') F[++s]=ff, K[ff]++;
		else if(t=='=') break;
	}
	
	scanf("%d",&n);
	
	a = K[0]+n, b = K[0]*n+n, c = K[1], d = K[1]*n;
	
	if(b<c || d<a){
		printf("Impossible\n");
		return 0;
	}
	
	else if(a<=c && c<=b) k=c;
	else if(a<=d && d<=b) k=d;
	else if(c<=a && a<=d) k=a;
	else if(c<=b && b<=d) k=b;
	
	int kp=k-K[1];
	c=n-1;
	for(i=0;i<K[1];i++){
		if(kp==0) c=0;
		else if(kp-c<0) c=kp;
		kp -= c;
		P.push_back(c+1);
	}
	kp=k-K[0]-n;
	c=n-1;
	for(i=0;i<K[0];i++){
		if(kp==0) c=0;
		else if(kp-c<0) c=kp;
		kp -= c;
		M.push_back(c+1);
	}
	
	printf("Possible\n");
	
	for(i=0;i<s;i++){
		if(i) printf(" %c ",F[i+1]?'+':'-');
		if(F[i+1]){
			printf("%d",P.back());
			P.pop_back();
		}
		else{
			printf("%d",M.back());
			M.pop_back();
		}
	}
	
	printf(" = %d\n",n);
	
	return 0;
}