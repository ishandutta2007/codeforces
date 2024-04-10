#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define P pair<L,L>
vector<P>V,A;
P seg;
inline void Merge(P tem){
	if(seg.second<tem.first-1){
		A.push_back(seg);
		seg=tem;
	}else if(seg.second<tem.second){
		seg.second=tem.second;
	}
}
int main(){
	int h,q,dep,k;
	scanf("%d%d",&h,&q);
	L x,y;
	for(R i=0;i!=q;i++){
		scanf("%d",&dep);
		scanf("%lld%lld",&x,&y);
		x<<=h-dep;
		y=(y+1<<h-dep)-1;
		scanf("%d",&k);
		if(k==0){
			V.push_back(make_pair(x,y));
		}else{
			if(x!=(1ll<<h-1)){
				V.push_back(make_pair(1ll<<h-1,x-1));
			}
			if(y!=(1ll<<h)-1){
				V.push_back(make_pair(y+1,(1ll<<h)-1));
			}
		}
	}
	if(V.size()==0){
		if(h==1){
			printf("1");
		}else{
			printf("Data not sufficient!");
		}
		return 0;
	}
	sort(V.begin(),V.end());
	seg=V[0];
	k=V.size();
	for(R i=1;i!=k;i++){
		Merge(V[i]);
	}
	A.push_back(seg);
	sort(A.begin(),A.end());
	L sum=0;
	k=A.size();
	for(R i=0;i!=k;i++){
		sum+=A[i].second-A[i].first+1;
	}
	if(sum==1ll<<h-1){
		printf("Game cheated!");
	}else if(sum==(1ll<<h-1)-1){
		if(k==2){
			printf("%lld",A[0].second+1);
		}else{
			if(A[0].second==(1ll<<h)-1){
				printf("%lld",1ll<<h-1);
			}else{
				printf("%lld",(1ll<<h)-1);
			}
		}
	}else{
		printf("Data not sufficient!");
	}
	return 0;
}