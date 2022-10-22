#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int sol[1002][1002];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		int p=2;
		for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        sol[i][j]=(i/p)*(N)*(p)+(j/p)*p*p+(i%p)*p+j%p;
      }
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
}