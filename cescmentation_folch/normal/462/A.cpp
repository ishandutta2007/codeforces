#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;

bool xec(VVI G, int n){
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			if(G[i][j]%2==1)return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	VVI G(n,VI(n,0));
	char c;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			cin>>c;
			if(c == 'o'){			
				if(i > 0) ++G[i-1][j];
				if(i < n-1) ++G[i+1][j];
				if(j > 0) ++G[i][j-1];
				if(j < n-1) ++G[i][j+1];
			}
		}
	}
	if(xec(G,n)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
 
}