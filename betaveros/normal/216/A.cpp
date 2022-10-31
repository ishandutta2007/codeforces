#include <cstdio>
using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", a*b + a*c + b*c -a -b -c +1  );
}