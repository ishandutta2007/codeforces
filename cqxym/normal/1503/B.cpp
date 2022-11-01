#include<iostream>
#include<vector>
using namespace std;
#define R register int
int main(){
	int n,a,b,c;
	cin>>n>>a;
	if(a==1){
		a=2;
	}else{
		a=1;
	}
	cout<<a<<" 1 1"<<endl;
	cin>>b;
	if(a!=1&&b!=1){
		b=1;
	}else if(a!=2&&b!=2){
		b=2;
	}else{
		b=3;
	}
	cout<<b<<" 1 2"<<endl;
	c=a^b;
	vector<pair<int,int> >A1,A2;
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			if(i>1||j>2){
				if((i+j&1)==0){
					A1.push_back(make_pair(i,j));
				}else{
					A2.push_back(make_pair(i,j));
				}
			}
		}
	}
	for(R i=n*n;i!=2;i--){
		int x;
		cin>>x;
		pair<int,int>P;
		if(x==a){
			if(A2.empty()==true){
				P=*A1.rbegin();
				A1.pop_back();
				x=c;
			}else{
				P=*A2.rbegin();
				A2.pop_back();
				x=b;
			}
		}else if(x==b){
			if(A1.empty()==true){
				P=*A2.rbegin();
				A2.pop_back();
				x=c;
			}else{
				P=*A1.rbegin();
				A1.pop_back();
				x=a;
			}
		}else if(A1.empty()==false){
			P=*A1.rbegin();
			A1.pop_back();
			x=a;
		}else{
			P=*A2.rbegin();
			A2.pop_back();
			x=b;
		}
		cout<<x<<' '<<P.first<<' '<<P.second<<endl;
	}
	return 0;
}