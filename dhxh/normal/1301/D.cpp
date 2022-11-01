#include <bits/stdc++.h>

using namespace std;

int n, m, k;

vector <pair <int, char> > vec, A;

int main(){
	int i, j;
	
	scanf("%d%d%d", &n, &m, &k);
	
	if(4 * n * m - 2 * n - 2 * m < k){
		printf("NO\n");
		return 0;
	}else{
		printf("YES\n");
	}
	
	for(i=2;i<=n;i++){
		vec.push_back(make_pair(1, 'D'));
		k--;
		if(!k)break;
		if(k <= m - 1){
			vec.push_back(make_pair(k, 'R'));
			k = 0;
			break;
		}else{
			vec.push_back(make_pair(m - 1, 'R'));
			k -= m - 1;
		}
		
		if(k <= m - 1){
			vec.push_back(make_pair(k, 'L'));
			k = 0;
			break;
		}else{
			vec.push_back(make_pair(m - 1, 'L'));
			k -= m - 1;
		}
	}
	
	if(k){
		if(k <= n - 1){
			vec.push_back(make_pair(k, 'U'));
			k = 0;
		}else{
			vec.push_back(make_pair(n - 1, 'U'));
			k -= n - 1;
		}
	}
	
	if(k){
		for(i=2;i<=m;i++){
			vec.push_back(make_pair(1, 'R'));
			k--;
			if(!k)break;
			if(k <= n - 1){
				vec.push_back(make_pair(k, 'D'));
				k = 0;
				break;
			}else{
				vec.push_back(make_pair(n - 1, 'D'));
				k -= n - 1;
			}
			
			if(k <= n - 1){
				vec.push_back(make_pair(k, 'U'));
				k = 0;
				break;
			}else{
				vec.push_back(make_pair(n - 1, 'U'));
				k -= n - 1;
			}
		}
	}
	
	if(k){
		if(k <= m - 1){
			vec.push_back(make_pair(k, 'L'));
			k = 0;
		}else{
			vec.push_back(make_pair(m - 1, 'L'));
			k -= m - 1;
		}
	}
	
	vector <pair <int, char> > A;
	
	for(pair <int, char> tmp : vec){
		if(tmp.first) A.push_back(tmp);
	}
	
	vec = A;
	
	printf("%d\n", vec.size());
	
	for(pair <int, char> tmp : vec){
		printf("%d %c\n", tmp.first, tmp.second);
	}
	
	return 0;
}