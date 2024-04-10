/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=400000,M=400000;
bool hav[N];
int now[M];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)now[i]=i;
	int now0=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		hav[now[x%m]]=true;
		now[x%m]+=m;if(now[x%m]>=n)now[x%m]-=m;
		while(hav[now0])now0++;
		cout<<now0<<"\n";
	}
	return 0;
}