#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
#define INF 1000000000
struct Point{
	int PosX,PosY;
	I void Read(){
		scanf("%d%d",&PosX,&PosY);
	}
};
vector<Point>A[3];
I bool CompareX(Point A,Point B){
	return A.PosX<B.PosX;
}
I bool CompareY(Point A,Point B){
	return A.PosY<B.PosY;
}
I bool Check(int lx,int ly,int rx,int ry,vector<int>C,const int k){
	if(lx>rx||ly>ry){
		return false;
	}
	if(C.empty()==true){
		return true;
	}
	for(int T:C){
		vector<int>D;
		for(int T2:C){
			if(T2!=T){
				D.push_back(T2);
			}
		}
		vector<Point>Px,Py;
		for(auto P:A[T]){
			if(lx<=P.PosX&&P.PosX<=rx&&ly<=P.PosY&&P.PosY<=ry){
				Px.push_back(P);
				Py.push_back(P);
			}
		}
		int s=Px.size();
		if(s>=k){
			sort(Px.begin(),Px.end(),CompareX);
			sort(Py.begin(),Py.end(),CompareY);
			if(Check(Px[k-1].PosX+1,ly,rx,ry,D,k)==true||Check(lx,ly,Px[s-k].PosX-1,ry,D,k)==true||Check(lx,Py[k-1].PosY+1,rx,ry,D,k)==true||Check(lx,ly,rx,Py[s-k].PosY-1,D,k)==true){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n,c,l=1,r,mid,ans;
	scanf("%d",&n);
	r=n/3;
	for(R i=0;i!=n;i++){
		Point B;
		B.Read();
		scanf("%d",&c);
		A[c-1].push_back(B);
	}
	vector<int>C;
	C.push_back(0);
	C.push_back(1);
	C.push_back(2);
	while(l<=r){
		mid=l+r>>1;
		if(Check(-INF,-INF,INF,INF,C,mid)==true){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans*3);
	return 0;
}