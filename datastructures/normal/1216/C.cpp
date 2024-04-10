#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int x1,y1,x2,y2;
}a1,a2,a3;
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>a1.x1>>a1.y1>>a1.x2>>a1.y2;
	cin>>a2.x1>>a2.y1>>a2.x2>>a2.y2;
	cin>>a3.x1>>a3.y1>>a3.x2>>a3.y2;
	int f=1;
	for (int i=a1.x1+1;i<=a1.x2;i++){
		int flag=0;
		if (a2.x1<i&&a2.x2>=i){
			if (a2.y1<=a1.y1&&a2.y2>=a1.y2)flag=1;
			else if (a2.y1<=a1.y1&&a3.y1<=a2.y2&&a3.y2>=a1.y2&&(a3.x1<i&&a3.x2>=i))flag=1;
		}
		if (a3.x1<i&&a3.x2>=i){
			if (a3.y1<=a1.y1&&a3.y2>=a1.y2)flag=1;
			else if (a3.y1<=a1.y1&&a2.y1<=a3.y2&&a2.y2>=a1.y2&&(a2.x1<i&&a2.x2>=i))flag=1;
		}
		if (flag==0)f=0;
	}
	if (f==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}