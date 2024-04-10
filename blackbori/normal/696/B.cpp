#include <cstdio>
#include <vector>

using namespace std;

struct tree{
	int num,par;
	double t;
	vector <int> des;
}A[101010];

int n;

int F(int k,double t)
{
	int i;
	
	t+=1.0;
	A[k].t = t;
	for(i=0;i<A[k].des.size();i++){
		F(A[k].des[i],t+(A[k].num-A[A[k].des[i]].num-1)/2.0);
	}
	
	return 0;
}

int G(int k)
{
	int i;
	
	A[k].num=1;
	for(i=0;i<A[k].des.size();i++) A[k].num += G(A[k].des[i]);
	
	return A[k].num;
}

int main()
{
	scanf("%d",&n);
	
	int i;
	
	for(i=2;i<=n;i++) scanf("%d",&A[i].par), A[A[i].par].des.push_back(i);
	
	G(1);
	
	for(i=1;i<=n;i++) A[i].t=0.0;
	
	F(1,0.0);
	
	for(i=1;i<=n;i++) printf("%lf ",A[i].t);
	printf("\n");
	
	return 0;
}