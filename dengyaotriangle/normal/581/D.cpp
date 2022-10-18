#include<bits/stdc++.h>
using namespace std;

struct d{
	int x,y;
};

d f[10];

int main(){
	cin>>f[0].x>>f[0].y>>f[1].x>>f[1].y>>f[2].x>>f[2].y;
	int sqr=f[0].x*f[0].y+f[1].x*f[1].y+f[2].x*f[2].y;
	int fd=-1;
	for(int i=1;i<=100;i++){
		if(i*i==sqr) fd=i;
	}
	if(fd==-1){
		cout<<-1;
		return 0;
	}
	if(f[0].x>fd||f[0].y>fd||f[1].x>fd||f[1].y>fd||f[2].x>fd||f[2].y>fd){
		cout<<-1;
		return 0;
	}
	for(int j=0;j<40;j++){
		if(1&(j)) swap(f[0].x,f[0].y);
		if(1&(j>>1)) swap(f[1].x,f[1].y);
		if(1&(j>>2)) swap(f[2].x,f[2].y);
		if(f[0].x==f[1].x&&f[1].x==f[2].x&&f[2].x==fd){
			cout<<fd<<endl;
			for(int i=0;i<f[0].y;i++){
				for(int k=0;k<fd;k++) cout<<'A';
				cout<<endl;
			}
			for(int i=0;i<f[1].y;i++){
				for(int k=0;k<fd;k++) cout<<'B';
				cout<<endl;
			}
			for(int i=0;i<f[2].y;i++){
				for(int k=0;k<fd;k++) cout<<'C';
				cout<<endl;
			}
			return 0;
		}
		int p[3]={0,1,2};
		char c[3]={'A','B','C'};
		for(int i=0;i<10;i++){
			if(f[p[0]].x==fd&&f[p[1]].x+f[p[2]].x==fd&&f[p[1]].y==f[p[2]].y){
				cout<<fd<<endl;
				for(int i=0;i<f[p[0]].y;i++){
					for(int k=0;k<fd;k++) cout<<c[0];
					cout<<endl;
				}
				for(int i=0;i<f[p[1]].y;i++){
					for(int k=0;k<f[p[1]].x;k++) cout<<c[1];
					for(int k=0;k<f[p[2]].x;k++) cout<<c[2];
					cout<<endl;
				}
				return 0;
			}
			next_permutation(p,p+3);
			next_permutation(c,c+3);
		}
		if(1&(j)) swap(f[0].x,f[0].y);
		if(1&(j>>1)) swap(f[1].x,f[1].y);
		if(1&(j>>2)) swap(f[2].x,f[2].y);
	}
	cout<<-1;
	return 0;
}