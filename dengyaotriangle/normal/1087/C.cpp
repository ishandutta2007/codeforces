#include<bits/stdc++.h>

using namespace std;

struct pt{
	int x,y;
};

pt p[5];

bool cmp(pt a,pt b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int absl(int a){
	if(a<0) return 0-a;
	return a;
}
int main(){
	cin>>p[1].x>>p[1].y;
	cin>>p[2].x>>p[2].y;
	cin>>p[3].x>>p[3].y;
	sort(p+1,p+4,cmp);
	if(p[1].y<=p[2].y&&p[2].y<=p[3].y){
		cout<<p[3].y-p[1].y+p[3].x-p[1].x+1<<endl;
		for(int i=p[1].x;i<p[2].x;i++) cout<<i<<' '<<p[1].y<<endl;
		for(int i=p[1].y;i<p[2].y;i++) cout<<p[2].x<<' '<<i<<endl;
		for(int i=p[2].x;i<p[3].x;i++) cout<<i<<' '<<p[2].y<<endl; 
		for(int i=p[2].y;i<=p[3].y;i++) cout<<p[3].x<<' '<<i<<endl; 
		return 0;
	}
	if(p[1].y>=p[2].y&&p[2].y>=p[3].y){
		cout<<p[1].y-p[3].y+p[3].x-p[1].x+1<<endl;
		for(int i=p[1].x;i<p[2].x;i++) cout<<i<<' '<<p[1].y<<endl;
		for(int i=p[1].y;i>p[2].y;i--) cout<<p[2].x<<' '<<i<<endl;
		for(int i=p[2].x;i<p[3].x;i++) cout<<i<<' '<<p[2].y<<endl; 
		for(int i=p[2].y;i>=p[3].y;i--) cout<<p[3].x<<' '<<i<<endl; 
		return 0;
	}
	if(p[1].y<=p[2].y&&p[2].y>=p[3].y){
		if(p[3].y>=p[1].y){
			cout<<p[3].y-p[1].y+p[3].x-p[1].x+p[2].y-p[3].y+1<<endl;
			for(int i=p[1].y;i<p[3].y;i++) cout<<p[1].x<<' '<<i<<endl;
			for(int i=p[1].x;i<=p[3].x;i++) cout<<i<<' '<<p[3].y<<endl;
			for(int i=p[2].y;i>p[3].y;i--) cout<<p[2].x<<' '<<i<<endl;
		}else{
			cout<<p[2].y-p[1].y+absl(p[3].y-p[1].y)+p[3].x-p[1].x+1<<endl;
			for(int i=p[1].x;i<p[3].x;i++) cout<<i<<' '<<p[1].y<<endl;
			for(int i=p[1].y;i>=p[3].y;i--) cout<<p[3].x<<' '<<i<<endl;
			for(int i=p[2].y;i>p[1].y;i--) cout<<p[2].x<<' '<<i<<endl; 
		}
		return 0;
	}
	if(p[1].y>=p[2].y&&p[2].y<=p[3].y){
		if(p[3].y<=p[1].y){
			cout<<p[3].x-p[1].x+p[1].y-p[3].y+p[3].y-p[2].y+1<<endl; 
			for(int i=p[1].y;i>p[3].y;i--) cout<<p[1].x<<' '<<i<<endl;
			for(int i=p[1].x;i<=p[3].x;i++) cout<<i<<' '<<p[3].y<<endl;
			for(int i=p[2].y;i<p[3].y;i++) cout<<p[2].x<<' '<<i<<endl; 
		}
		else{
			cout<<p[1].y-p[2].y+absl(p[3].y-p[1].y)+p[3].x-p[1].x+1<<endl;
			for(int i=p[1].x;i<p[3].x;i++) cout<<i<<' '<<p[1].y<<endl;
			for(int i=p[1].y;i<=p[3].y;i++) cout<<p[3].x<<' '<<i<<endl;
			for(int i=p[2].y;i<p[1].y;i++) cout<<p[2].x<<' '<<i<<endl; 
		}
		return 0;
	}
}