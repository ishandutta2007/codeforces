#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
namespace Geometry{
	struct point{
		double x;double y;
		void print(){
			printf("Point:x:%.8lf,y:%.8lf",x,y);
		}
	};
	struct line{
		double x;double c;
		void print(){
			printf("Line:x:%.8lf,c:%.8lf\n",x,c);
		}
	};
	line make_line(point a,point b){
		double x=(a.x-b.x)/(a.y-b.y);
		double c=a.y-(a.x)*(x);
		return (line){x,c};
	}
}
using namespace Geometry;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
int main(){
	int n;
	cin>>n;
	n++;
	if(n<=57){
		int prex,prey;
		for(int i=1;i<=n-2;i++){
			int data=(i-1)/8+1;
			printf("%c%d ",'a'+(i-1)/8,data%2==1?(i%8==0?8:i%8):17-(i%16==0?16:i%16));
			prex=(i-1)/8+1;prey=data%2==1?(i%8==0?8:i%8):17-(i%16==0?16:i%16);
		}
		if(prex==8){
			printf("%c%d ",'a'+7,prey+1);
			printf("h8\n");
		}
		else if(prey==8){
			printf("%c%d ",'a'+prex,8);
			printf("h8\n");
		}
		else{
			printf("h%d ",prey);
			printf("h8\n");
		}
	}
	n--;
	if(n>56){
		int i;
		for(i='a';i<='h';++i) cout<<char(i)<<1<<' ';
		for(i='h';i>='a';--i) cout<<char(i)<<2<<' ';
		for(i='a';i<='h';++i) cout<<char(i)<<3<<' ';
		for(i='h';i>='a';--i) cout<<char(i)<<4<<' ';
		for(i='a';i<='h';++i) cout<<char(i)<<5<<' ';
		for(i='h';i>='a';--i) cout<<char(i)<<6<<' ';
		cout<<"a7 h7 g7 f7 e7 d7 c7 b7 b8 ";
		if(n==57) cout<<"h8"<<endl;
		else if(n==58) cout<<"c8 h8\n";
		else if(n==59) cout<<"c8 d8 h8\n";
		else if(n==60) cout<<"c8 d8 e8 h8\n";
		else if(n==61) cout<<"c8 d8 e8 f8 h8\n";
		else if(n==62) cout<<"c8 d8 e8 f8 g8 h8\n";
		else if(n==63) cout<<"a8 c8 d8 e8 f8 g8 h8\n";
		return 0;
	}
	return 0;
}