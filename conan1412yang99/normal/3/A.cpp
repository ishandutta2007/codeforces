#include <bits/stdc++.h>

using namespace std;

int main(){
	char a,c;
	int b,e,x,y,m,d,z=0;
	cin>>a>>b>>c>>e;
	x = a - c;
	y = b - e;
	if(a > c) m = x;
	else m = -x;
	if(b > e) d = y;
	else d = -y;
	//cout<<x<<y<<m<<d<<endl;
	if(x != 0 && y != 0){
		if(m - d > 0) z = d , cout<<m<<endl;;
		if(d - m > 0) z = m , cout<<d<<endl;;
		if(z == 0) z = m , cout<<z<<endl;;
		for(int i = 0 ; i < z ; i++){
			if(x>0){
				if(y>0) cout<<"LD"<<endl , x-- , y--;
				if(y<0) cout<<"LU"<<endl , x-- , y++;
			}
			if(x<0){
				if(y>0) cout<<"RD"<<endl , x++ , y--;
				if(y<0) cout<<"RU"<<endl , x++ , y++;
			}
		}
	}
	else cout<<m+d<<endl;
	m -= z;
	d -= z;
	//cout<<x<<y<<m<<d<<endl;
	if(m != 0){
		for(int i = 0 ; i < m ; i++){
			if(x>0)cout<<"L"<<endl;
			else cout<<"R"<<endl;
		}
	}
	if(d != 0){
		for(int i = 0 ; i < d ; i++){
			if(y>0)cout<<"D"<<endl;
			else cout<<"U"<<endl;
		}
	}
}