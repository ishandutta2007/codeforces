#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
#define INF 999999
inline void Solve(int l,int mid,int r,int lv,int mv,int rv){
	if(l==mid-1&&r==mid+1){
		cout<<"! "<<mid;
		cout.flush();
		exit(0);
	}
	int pos=l+rand()%(r-l-2)+1,v;
	if(pos>=mid){
		pos++;
	}
	cout<<"? "<<pos<<endl;
	cin>>v;
	if(pos<mid){
		if(v>mv){
			Solve(pos,mid,r,v,mv,rv);
		}else{
			Solve(l,pos,mid,lv,v,mv);
		}
	}else if(v<mv){
		Solve(mid,pos,r,mv,v,rv);
	}else{
		Solve(l,mid,pos,lv,mv,v);
	}
}
int main(){
	srand((int)time(0));
	int n,x,a;
	cin>>n;
	x=rand()%n+1;
	cout<<"? "<<x<<endl;
	cin>>a;
	Solve(0,x,n+1,INF,a,INF);
	return 0;
}