#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,m,x,y,Min,Count;
	cin >> n >> m;
	bool a[7][7];
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			a[i][j]=false;
		}
	}
	for(int i=0; i<m; i++){
		cin >> x >> y;
		a[x-1][y-1]=a[y-1][x-1]=true;
	}
	if(n<=6) cout << m << endl;
	else{
		Min=INT_MAX;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				Count=0;
				if(i!=j){
					for(int k=0; k<n; k++){
						if(k!=i&&k!=j) if(a[k][i]&&a[k][j]) Count++;
					}
					if(Count<Min) Min=Count;
				}
			}
		}
		cout << m-Min << endl;
	}
	return 0;
}