#include <bits/stdc++.h>

using namespace std;

struct point{
	int a, b, i;
	point() {}
	point(int a, int b, int i) : a(a), b(b), i(i) {}
};

vector <point> X, Y;
int n;

int main()
{
	int i, a, b;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d%d", &a, &b);
		if(a < b) X.emplace_back(a, b, i);
		else Y.emplace_back(a, b, i);
	}
	
	if(X.size() >= Y.size()){
		printf("%d\n", X.size());
		
		sort(X.begin(), X.end(), [&](point &pa, point &pb){
			return pa.a > pb.a;
		});
		
		for(i=0; i<X.size(); i++){
			printf("%d ", X[i].i);
		}
		
		printf("\n");
	}
	else{
		printf("%d\n", Y.size());
		
		sort(Y.begin(), Y.end(), [&](point &pa, point &pb){
			return pa.a < pb.b;
		});
		
		for(i=0; i<Y.size(); i++){
			printf("%d ", Y[i].i);
		}
		
		printf("\n");
	}
	
	return 0;
}