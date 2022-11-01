#include <bits/stdc++.h>

using namespace std;

int n, m, t;

const int maxn = 2e6 + 5;

char a[maxn];

int main(){
	int i, j, k;
	char ch;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		scanf("%s", a);
		
		int mx = max(0, m - 20);
		int cnt = 0;
		
		for(i=0;i<mx-1;i++){
			if(a[i] == '1') cnt++;
			else cnt = 0;
		}
		
		vector <int> vec;
		
		for(i=mx-1;i+m-mx<n;i++){
			if(a[i] == '1') cnt++;
			else cnt = 0;
			if(cnt >= mx){
				int tmp = 0;
				for(j=1;j<=m-mx;j++){
					tmp = tmp * 2 + a[i + j] - '0';
				}
				vec.push_back(tmp);
			}
		}
		
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
		reverse(vec.begin(), vec.end());
		cnt = (1 << (m - mx)) - 1;
		
		for(auto x : vec){
			if(x == cnt){
				cnt--;
			}else{
				break;
			}
		}
		
		if(cnt == -1){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(i=1;i<=mx;i++){
				printf("0");
			}
			for(i=0;i<m-mx;i++){
				int p = (cnt >> (m - mx - i - 1)) & 1;
				printf("%d", !p);
			}
			printf("\n");
		}
	}
	
	return 0;
}