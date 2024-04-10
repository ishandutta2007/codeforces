#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e4+100;
const int MAGIC = 1200;
bool used[MAX];
int bestvalue;
int bestindex;
#define random(a,b) rand()*rand()%(b-a+1)+a
const int INF = 0x3f3f3f3f;
int value,nxt,x,n,st;
int main(){
	srand(time(NULL));
	scanf("%d%d%d",&n,&st,&x);
	cout<<"? "<<st<<endl;
	scanf("%d%d",&bestvalue,&nxt);
//	assert(nxt!=-1||n==1);
	bestindex = st;
	if (bestvalue>=x){
		cout<<"! "<<bestvalue<<endl;
		return 0;
	}
	if (n<1900){
		while (true){
			cout<<"? "<<bestindex<<endl;
			scanf("%d%d",&value,&bestindex);
			if (value>=x){
				cout<<"! "<<value<<endl;
				return 0;
			}
			if (bestindex==-1){
				cout<<"! -1\n"<<endl;
				return 0;
			}
		}
	}
	for (int i=0;i<MAGIC;i++){
		int tt=random(1,n);
		while (used[tt])tt = random(1,n);
		used[tt] = true;
//		printf("? %d\n",tt);
//		fflush(stdout);
		cout<<"? "<<tt<<endl;
		scanf("%d%d",&value,&nxt);
		if (value==x){
//			printf("! %d\n",value);
//			fflush(stdout);
			cout<<"! "<<value<<endl;
			return 0;
		}
		if (value<x){
			if (value>bestvalue){
				bestvalue = value;
				bestindex = tt;
			}
		}
	}
//	if (n==50000){
//		cout<<bestvalue<<endl;
//		return 0;
//	}
	for (int i=0;i<=795;i++){
		cout<<"? "<<bestindex<<endl;
		scanf("%d%d",&value,&nxt);
		if (value>=x){

			cout<<"! "<<value<<endl;
			return 0;
		}
		if (nxt==-1){
			cout<<"! -1"<<endl;
			return 0;
		}
		bestindex = nxt;
	}
	cout<<bestvalue<<endl;
	return 0;
}