#include<bits/stdc++.h>
using namespace std;
vector<long long>fa;
long long gcd(long long x,long long y){return y==0?x:gcd(y,x%y);}
long long f(long long x,long long y){
	if(y==0)return 0; 
	long long gc=gcd(max(x,y),min(x,y));x/=gc;y/=gc;
	if(y==1)return 1;
	if(x==1)return y;
	fa.clear();
	long long tmp=x;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)fa.push_back(i);
		while(x%i==0)x/=i;
	}
	if(x!=1)fa.push_back(x);
	x=tmp;
	long long eraser=1000000000001;
	for(int i=0;i<fa.size();i++)
		eraser=min(eraser,y%fa[i]);
	y-=eraser;
	return f(x,y)+eraser;
}
int main(){
	long long x,y;
	cin>>x>>y;
	cout<<f(x,y);
}