#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int stato[200];
bool cambio[200][100009];
int somma(){
	int tot=0;
	for(int i=0;i<110;i++)tot+=stato[i];
	return tot;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N;
		cin>>N;
		string a;
		cin>>a;
		for(int i=0;i<N;i++)stato[i]=a[i]-'0';
		for(int i=0;i<N;i++){
			int b,c;
			cin>>c>>b;
			for(int j=b;j<100000;j+=c)cambio[i][j]=1;
		}
		int ma=somma();
		for(int i=1;i<100000;i++){
			for(int j=0;j<N;j++)if(cambio[j][i])stato[j]=!stato[j];
			ma=max(ma,somma());
		}
		cout<<ma;
		return 0;
}