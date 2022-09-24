#include<bits/stdc++.h>
using namespace std;

int n, si, kol, mako=-1;
string s; 
char c, cc, x, xx, f, ff;

int main (){
	cin >> n >> s;
	if (n==2){
		cout <<s;
	}else 
	if (n==3){
		cout << s[0] << s[1];
	}else {
	for (int i=0; i<n-1; i++){
		c=s[i];
		cc=s[i+1];
		for (int j=i+1; j<n-1; j++){
			x=s[j];
			xx=s[j+1];
			if (x==c && xx==cc){
				kol=kol+1;
			}
		}
		if (kol>mako){
			f=c; 
			ff=cc;
			mako=kol;
		}
		kol=0;
	}
	cout <<f << ff;}
	return 0; 
}