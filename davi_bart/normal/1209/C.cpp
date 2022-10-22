#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--){
			int N;
			cin>>N;
			string k;
			cin>>k;
			vector<int> v[12];
			vector<int> sol(N+2,0);
			for(int i=0;i<N;i++)v[k[i]-'0'].push_back(i);
			int ma=-1;
			bool cambio=0,perso=0;
			int colore=1;
			for(int i=0;i<10;i++){
				if(v[i].size()==0)continue;
				if(v[i][0]>ma){
					for(int j=0;j<v[i].size();j++)sol[v[i][j]]=colore;
					ma=v[i].back();
				}else{
					if(cambio){
						perso=1;
						break;
					}
					cambio=1;
					colore=2;
					int c=0;
					for(int j=0;j<v[i].size();j++){
						if(v[i][j]<ma){
							sol[v[i][j]]=2;
							c=j;
						}else{
							sol[v[i][j]]=1;
						}
					}
					ma=v[i][c];
				}
			}
			if(perso)cout<<'-'<<'\n';
			else{
				for(int i=0;i<N;i++)cout<<sol[i];
				cout<<'\n';
			}
		}
		return 0;
}