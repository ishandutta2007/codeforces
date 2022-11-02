#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[1000];
vector<pair<int,int> >ans;
int main(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum != 0){
		puts("YES");
		puts("1");
		printf("%d %d\n",1, n);
	}
	else{
		int last = 0;
		sum = 0;
		for(int i = 1; i <= n; i++){
			if(a[i]){
				ans.push_back(make_pair(1, i));
				if(i < n)
					ans.push_back(make_pair(i + 1, n));
				break;
			}
			
		}
		if((int)ans.size() == 0)
			puts("NO");
		else{
			puts("YES");
			cout << ans.size() <<endl;
			for(auto x : ans){
				cout << x.first << " " << x.second << endl;
			}
		}
	}
	return 0;
}