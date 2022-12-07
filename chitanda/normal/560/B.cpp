#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a1,a2,b1,b2,c1,c2;
int main(){
	//	freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
	if (b1 + c1 <= a1 && b2 <= a2 && c2 <= a2){
		printf("YES");
	}else if(b2 + c2 <= a1 && b1 <= a2 && c1 <= a2){
		printf("YES");
	}else if(b1 + c2 <= a1 && b2 <= a2 && c1 <= a2){
		printf("YES");
	}else if(b2 + c1 <= a1 && b1 <= a2 && c2 <= a2){
		printf("YES");
	}else if(b1 + c1 <= a2 && b2 <= a1 && c2 <= a1){
		printf("YES");
	}else if(b1 + c2 <= a2 && b2 <= a1 && c1 <= a1){
		printf("YES");
	}else if(b2 + c2 <= a2 && b1 <= a1 && c1 <= a1){
		printf("YES");
	}else if(b2 + c1 <= a2 && b1 <= a1 && c2 <= a1){
		printf("YES");
	}else printf("NO");
																								
		
	return 0;
}