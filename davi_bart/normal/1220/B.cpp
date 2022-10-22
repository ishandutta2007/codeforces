#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll p[1001][1001];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>p[i][j];
      }
		}
    for(int i=0;i<N;i++){
      ll k;
      if(i>N-2)k=p[i][i-1]*p[i][i-2]/p[i-1][i-2];
      else if(i==N-2)k=p[i][i-1]*p[i][i+1]/p[i-1][i+1];
      else k=p[i][i+1]*p[i][i+2]/p[i+1][i+2];
      cout<<(int)sqrt(k)<<" ";
    }

		return 0;
}