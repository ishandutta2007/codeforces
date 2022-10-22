#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y,z,a,b,c;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if(x > a){
		puts("NO");
		return 0;
	}
	a -= x;
	y -= a;
	if(y > b){
		puts("NO");
		return 0;
	}
	b -= y;
	z -= b;
	if(z > c){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}