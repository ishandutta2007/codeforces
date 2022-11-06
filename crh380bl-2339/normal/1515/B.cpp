#include<bits/stdc++.h>
using namespace std;
bool sq(int x){
	int y=(int)sqrt((double)x);
	return y*y==x;
}
int main(){
	int n,m;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		if(m&1){
			puts("NO");
		}
		else{
			if(sq(m)||sq(m>>1))puts("YES");
			else puts("NO");
		}
	}
	return 0;
}