#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int n,m;
bool arr[52][52];
bool test(int a, int b){
	if(a>=0&&a<n-1&&b>=0&&b<m-1){
		if(arr[a][b]&&arr[a+1][b]&&arr[a][b+1]&&arr[a+1][b+1])return true;
		return false;
	}
	return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>arr[i][j];
    	}
    }
    vector<pii> vec;
    bool work=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				if(test(i,j)){
					vec.push_back({i,j});
				}
				else if(test(i-1,j)){
					vec.push_back({i-1,j});
				}
				else if(test(i,j-1)){
					vec.push_back({i,j-1});
				}
				else if(test(i-1,j-1)){
					vec.push_back({i-1,j-1});
				}
				else{
					work=false;
				}
			}
		}
	}
	if(!work){
		printf("-1\n");
		return 0;
	}
	else{
		printf("%d\n",vec.size());
		for(auto x:vec){
			printf("%d %d\n",x.first+1,x.second+1);
		}
	}
    return 0;
}