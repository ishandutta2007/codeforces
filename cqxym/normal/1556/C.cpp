#include<iostream>
#include<vector>
using namespace std;
#define R register int
int a[1000];
int main(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	long long ans=0;
	for(R i=0;i<n;i+=2){
		vector<pair<int,long long> >S;
		for(R j=i+1;j!=n;j++){
			if((j&1)==1){
				long long x=0,y=0;
				int lt=S.size()-1;
				if(lt>-1&&S[lt].first==-1){
					y=S[lt].second;
					lt--;
				}
				if(lt>-1){
					x=S[lt].second;
				}
				long long p=min(a[i]-x,a[j]-y);
				if(p>-1){
					if(j==i+1){
						ans+=p;
					}else{
						ans+=p+1;
					}
				}
			}
			int x=(j&1)==1?1:-1,y=a[j];
			if(x==1&&S.empty()==false&&S.back().first!=1){
				if(S.back().second>y){
					S.back().second-=y;
					y=0;
				}else{
					y-=S.back().second;
					S.pop_back();
				}
			}
			if(y!=0){
				if(S.empty()==false&&S.back().first==x){
					S.back().second+=y;
				}else{
					S.push_back(make_pair(x,y));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}