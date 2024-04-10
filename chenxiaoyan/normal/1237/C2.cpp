/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
const int N=50000;
int n;
pair<pair<int,int>,pair<int,int> > p[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].X.X>>p[i].X.Y>>p[i].Y.X,p[i].Y.Y=i;
	sort(p+1,p+n+1);
//	for(int i=1;i<=n;i++)printf("(%d,%d,%d,%d)\n",p[i].X.X,p[i].X.Y,p[i].Y.X,p[i].Y.Y);
	vector<int> v1;
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(ie<=n&&p[i].X.X==p[ie].X.X)ie++;ie--;
//		printf("[%d,%d]\n",i,ie);
		vector<int> v2;
		for(int j=i,je;j<=ie;j=je+1){
			je=j;while(je<=ie&&p[j].X.Y==p[je].X.Y)je++;je--;
//			printf("{%d,%d}\n",j,je);
			for(int k=j;k<je;k+=2)cout<<p[k].Y.Y<<" "<<p[k+1].Y.Y<<"\n";
			if(je-j+1&1)v2.pb(je);
		}
		for(int j=0;j+1<v2.size();j+=2)cout<<p[v2[j]].Y.Y<<" "<<p[v2[j+1]].Y.Y<<"\n";
		if(v2.size()&1)v1.pb(v2.back());
	}
	for(int i=0;i<v1.size();i+=2)cout<<p[v1[i]].Y.Y<<" "<<p[v1[i+1]].Y.Y<<"\n";
	return 0;
}