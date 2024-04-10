#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
struct Tree{
	int apple,pos;
};
inline bool Com1(Tree &x,Tree &y){
	return x.pos<y.pos;
}
inline bool Com2(Tree &x,Tree &y){
	return x.pos>y.pos;
}
vector<Tree>A,B;
int main(){
	int n,x,y,t;
	scanf("%d",&n);
	Tree Tem;
	for(R i=0;i!=n;i++){
		scanf("%d%d",&x,&y);
		Tem.apple=y;
		Tem.pos=x;
		if(x<0){
			A.push_back(Tem);
		}else{
			B.push_back(Tem);
		}
	}
	sort(A.begin(),A.end(),Com2);
	sort(B.begin(),B.end(),Com1);
	x=A.size();
	y=B.size();
	t=x<y?x:y;
	n=0;
	for(R i=0;i!=t;i++){
		n+=A[i].apple;
	}
	for(R i=0;i!=t;i++){
		n+=B[i].apple;
	}
	if(x>y){
		n+=A[t].apple;
	}else if(x<y){
		n+=B[t].apple;
	}
	printf("%d",n);
	return 0;
}