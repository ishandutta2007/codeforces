#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
#define R register int
int a[200],b[200];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	set<int>P[200];
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=m;i++){
		scanf("%d",b+i);
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			P[i].insert(b[j]);
		}
	}
	int ans=0;
	for(R t=8;t!=-1;t--){
		bool res=true;
		for(R i=0;i!=n;i++){
			bool tag=false;
			for(set<int>::iterator T=P[i].begin();T!=P[i].end();T++){
				if(((*T&a[i])>>t&1)==0){
					tag=true;
					break;
				}
			}
			res=res&&tag;
		}
		if(res==false){
			ans|=1<<t;
		}else{
			for(R i=0;i!=n;i++){
				vector<int>Tem;
				for(set<int>::iterator T=P[i].begin();T!=P[i].end();T++){
					if(((*T&a[i])>>t&1)==1){
						Tem.push_back(*T);
					}
				}
				for(vector<int>::iterator T=Tem.begin();T!=Tem.end();T++){
					P[i].erase(*T);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}