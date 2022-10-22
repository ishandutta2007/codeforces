#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool a[60][60],b[60][60];
vector<pair<int,int> > sol;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(a[i][j]){
					if(a[i+1][j] && a[i][j+1] && a[i+1][j+1]){
            sol.push_back({i+1,j+1});
            b[i][j]=1;b[i+1][j]=1;b[i+1][j+1]=1;b[i][j+1]=1;
					}
				}
			}
		}
		for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(a[i][j]!=b[i][j]){
          cout<<-1;
          return 0;
        }
      }
		}
		cout<<sol.size()<<endl;
		for(int i=0;i<sol.size();i++)cout<<sol[i].first<<" "<<sol[i].second<<endl;
		return 0;
}