#include<iostream>
#include<map>

using namespace std;

const int maxn=3;

long long k,a,b;
int ta[maxn][maxn],tb[maxn][maxn];
int x[10000],y[10000];
int xn[10000],yn[10000];
map <int ,int > m;

int w(int a,int b){
	if(a==b) return 0;
	if(a==3&&b==2) return 1;
	if(a==2&&b==1) return 1;
	if(a==1&&b==3) return 1;
	return -1;
}
int main(){
	cin>>k>>a>>b;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>ta[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>tb[i][j];
		}
	}
	if(k>10000){
		long long ca=0,cb=0,cl=0,sl;
		long long aa=0,ab=0;
		long long sa,sb;
		int xa=a,xb=b;
		while(true){
			m[xa*3+xb]=cl+1;
			x[cl]=ca;
			y[cl]=cb;
			xn[cl]=xa;
			yn[cl]=xb;
			//cout<<xa<<xb;
			if(w(xa,xb)==1){
				ca++;
			}else if(w(xa,xb)==-1){
				cb++;
			}
			int tmp=ta[xa-1][xb-1];
			xb=tb[xa-1][xb-1];
			xa=tmp;
			cl++;
			if(m[xa*3+xb]!=0){
				sa=xn[m[xa*3+xb]-1];
				sb=yn[m[xa*3+xb]-1];
				cl-=m[xa*3+xb]-1;
				aa=x[m[xa*3+xb]-1];
				ab=y[m[xa*3+xb]-1];
				tmp=ca-x[m[xa*3+xb]-1];
				sl=m[xa*3+xb]-1;
				cb=cb-y[m[xa*3+xb]-1];
				ca=tmp;
				break;
			}
		}
		//cout<<ca<<cb<<cl<<sl;
		long long tag=(k-sl)%cl;
		long long nl=0;
		xa=sa;
		xb=sb;
		while(nl<tag){
			if(w(xa,xb)==1){
				aa++;
			}else if(w(xa,xb)==-1){
				ab++;
			}
			int tmp=ta[xa-1][xb-1];
			xb=tb[xa-1][xb-1];
			xa=tmp;
			nl++;
		}
		cout<<ca*((k-sl)/cl)+aa<<' '<<cb*((k-sl)/cl)+ab;
	}else{
		long long aa=0,ab=0;
		int xa=a,xb=b;
		int nl=0;
		while(nl<k){
			if(w(xa,xb)==1){
				aa++;
			}else if(w(xa,xb)==-1){
				ab++;
			}
			int tmp=ta[xa-1][xb-1];
			xb=tb[xa-1][xb-1];
			xa=tmp;
			nl++;
		}
		cout<<aa<<' '<<ab;
	}
	return 0;
}