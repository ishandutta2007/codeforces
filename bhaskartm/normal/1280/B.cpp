#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int r, c;
		cin>>r>>c;
		char arr[r][c];
		bool b=0;
		bool b2=0;
		bool check=1;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin>>arr[i][j];
				if(arr[i][j]=='A'){
					b=1;
				}
				if(arr[i][j]=='P'){
					check=0;
				}
			}
		}
		if(check){
			cout<<0<<endl;
			continue;
		}
		if(b==0){
			cout<<"MORTAL"<<endl;
			continue;
		}
		b=1;
		for(int i=0; i<c; i++){
			if(arr[0][i]=='P'){
				b=0;
			}
			if(arr[0][i]=='A'){
				b2=1;
			}
		}
		if(b){
			cout<<1<<endl;
			continue;
		}
		b=1;
		for(int i=0; i<c; i++){
			if(arr[r-1][i]=='P'){
				b=0;
			}
			if(arr[r-1][i]=='A'){
				b2=1;
			}
		}
		if(b){
			cout<<1<<endl;
			continue;
		}
		b=1;
		for(int i=0; i<r; i++){
			if(arr[i][0]=='P'){
				b=0;
			}
			if(arr[i][0]=='A'){
				b2=1;
			}
		}
		if(b){
			cout<<1<<endl;
			continue;
		}
		b=1;
		for(int i=0; i<r; i++){
			if(arr[i][c-1]=='P'){
				b=0;
			}
			if(arr[i][c-1]=='A'){
				b2=1;
			}
		}
		if(b){
			cout<<1<<endl;
			continue;
		}
		bool d=0;
		for(int i=0; i<r; i++){
			bool booly=1;
			for(int j=0; j<c; j++){
				if(arr[i][j]=='P'){
					booly=0;
				}
			}
			if(booly){
				d=1;
			}
		}
		for(int i=0; i<c; i++){
			bool booly=1;
			for(int j=0; j<r; j++){
				if(arr[j][i]=='P'){
					booly=0;
				}
			}
			if(booly){
				d=1;
			}
		}
		if(d){
			cout<<2<<endl;
			continue;
		}
		if(arr[0][0]=='A' || arr[r-1][c-1]=='A' || arr[0][c-1]=='A' || arr[r-1][0]=='A'){
			cout<<2<<endl;
			continue;
		}
		if(b2){
			cout<<3<<endl;
			continue;
		}
		cout<<4<<endl;
		
	}
	return 0;
}