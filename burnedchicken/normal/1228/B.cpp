#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int h,w,x,y;
	cin >> h >> w;
	int r[h],c[w];
	bool k=true;
	for(int i=0; i<h; i++){
		cin >> r[i];
	}
	for(int i=0; i<w; i++){
		cin >> c[i];
	}
	int t[h][w];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			t[i][j]=0;
		}
	}
	for(int i=0; i<h; i++){
		if(r[i]==w){
			for(int j=0; j<w; j++){
				if(t[i][j]!=-1) t[i][j]=1;
				else{
					k=false;
					break;
				}
			}
		}
		else{
			for(int j=0; j<r[i]; j++){
				if(t[i][j]!=-1) t[i][j]=1;
				else{
					k=false;
					break;
				}
			}
			if(t[i][r[i]]!=1) t[i][r[i]]=-1;
			else{
				k=false;
				break;
			}
		}
		if(not k) break;
	}
	for(int i=0; i<w; i++){
		if(c[i]==h){
			for(int j=0; j<h; j++){
				if(t[j][i]!=-1) t[j][i]=1;
				else{
					k=false;
					break;
				}
			}
		}
		else{
			for(int j=0; j<c[i]; j++){
				if(t[j][i]!=-1) t[j][i]=1;
				else{
					k=false;
					break;
				}
			}
			if(t[c[i]][i]!=1) t[c[i]][i]=-1;
			else{
				k=false;
				break;
			}
		}
		if(not k) break;
	}
	if(not k) cout << 0 << endl;
	else{
		x=0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(t[i][j]==0) x++;
			}
		}
		y=1;
		for(int i=0; i<x; i++){
			y=y*2;
			y=y%1000000007;
		}
		cout << y << endl;
	}
	return 0;
}