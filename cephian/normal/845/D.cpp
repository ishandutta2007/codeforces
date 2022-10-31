#include <bits/stdc++.h>
using namespace std;

struct event {
	int t,v;
};
vector<event> e;
vector<int> limits = {1000},overtakes = {1};

int main() {	
	int n,ans=0,speed=0;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int t,v;
		scanf("%d",&t);
		if(t == 6 || t == 4) overtakes.push_back(t == 4);
		else if(t == 5) limits.push_back(1000);
		else if(t == 3) scanf("%d",&t), limits.push_back(t);
		else if(t == 2) {
			while(overtakes.back() == 0)
				++ans, overtakes.pop_back();
		} else if(t == 1) {
			scanf("%d",&speed);
		}
		while(speed > limits.back())
			++ans, limits.pop_back();
	}
	printf("%d\n",ans);
}