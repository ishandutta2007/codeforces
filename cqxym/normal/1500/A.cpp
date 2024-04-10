#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
struct Data{
	int Num,Id;
	inline friend bool operator<(Data A,Data B){
		return A.Num<B.Num;
	}
}a[200000];
bool vis[5000001];
pair<int,int>pos[5000001];
int main(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i].Num;
		a[i].Id=i;
	}
	sort(a,a+n);
	for(R i=0;i!=n;i++){
		for(R j=0;j!=i;j++){
			int d=a[i].Num-a[j].Num;
			if(vis[d]==true){
				if(pos[d].first!=j&&pos[d].second!=i&&pos[d].first!=i&&pos[d].second!=j){
					cout<<"YES"<<endl;
					printf("%d %d %d %d",a[i].Id+1,a[pos[d].first].Id+1,a[j].Id+1,a[pos[d].second].Id+1);
					return 0;
				}
			}else{
				vis[d]=true;
				pos[d]=make_pair(j,i);
			}
		}
	}
	printf("NO");
	return 0;
}