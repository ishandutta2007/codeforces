#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e9;
int ask(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl; cout.flush();
	cin>>x; return x;
}
void answerit(int x1,int y1,int x2,int y2){
	cout<<"! "<<min(x1,x2)<<" "<<min(y1,y2)<<" "<<max(x1,x2)<<" "<<max(y1,y2)<<endl;
}
int main()
{
	int L=ask(1,1),R=ask(N,1),q=1,ql,qr;
	if(L>R)ql=L-R+1,qr=N;
	else ql=1,qr=N-(R-L);
//	cerr<<"ql="<<ql<<" qr="<<qr<<endl;
	int mid=(ql+qr)/2;
	int upL=ask(mid,1);
	int x1=L-upL+1,y1=upL+1,x2=N-(R-upL),y2=N-ask(mid,N);
	answerit(x1,y1,x2,y2);
	return 0;
}