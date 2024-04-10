//And the clouds above move closer
//Looking so dissatisfied
//But the heartless wind kept blowing, blowing..

#include<cstdio>

using namespace std;

bool ok(int y){
	while (y){
		int t = y % 10;
		if (t != 4 && t != 7)	return	false;
		y /= 10;
	}
	return	true;
}

int main(){
	int x;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++){
		if (x % i != 0)	continue;
		if (ok(i)){
			printf("YES\n");
			return	0;
		}
	}
	printf("NO\n");
	return 0;
}