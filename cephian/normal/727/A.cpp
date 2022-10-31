#include <bits/stdc++.h>
using namespace std;

int a,b;
vector<int> ans;

int main() {	
	scanf("%d%d",&a,&b);
	while(b >= a) {
		if(b == a) {
			ans.push_back(b);
			break;
		}
		if(b%10 == 1) {
			ans.push_back(b);
			b /= 10;
		} else if(b % 2 == 0) {
			ans.push_back(b);
			b /= 2;
		} else break;
	}
	if(b == a) {
		printf("YES\n%d\n",(int)ans.size());
		for(int i = (int)ans.size()-1; i >= 0; --i)
			printf("%d ",ans[i]);
		printf("\n");
	} else printf("NO\n");
}