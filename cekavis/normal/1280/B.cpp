#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 66;
int T, r, c;
char s[N][N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &r, &c);
		bool o=0, p=0;
		for(int i=1; i<=r; ++i){
			scanf("%s", s[i]+1);
			for(int j=1; j<=c; ++j) o|=s[i][j]=='A', p|=s[i][j]=='P';
		}
		if(!o){
			puts("MORTAL");
			continue;
		}
		if(!p){
			puts("0");
			continue;
		}
		o=1;
		bool oo=0;
		for(int i=1; i<=r; ++i){
			bool p=0;
			for(int j=1; j<=c; ++j) p|=s[i][j]=='P';
			o&=p;
			oo|=(i==1 || i==r) && !p;
		}
		for(int j=1; j<=c; ++j){
			bool p=0;
			for(int i=1; i<=r; ++i) p|=s[i][j]=='P';
			o&=p;
			oo|=(j==1 || j==c) && !p;
		}
		if(o){
			if(s[1][1]=='A' || s[1][c]=='A' || s[r][1]=='A' || s[r][c]=='A')
				puts("2");
			else{
				o=0;
				for(int i=2; i<c; ++i) o|=s[1][i]=='A' || s[r][i]=='A';
				for(int i=2; i<r; ++i) o|=s[i][1]=='A' || s[i][c]=='A';
				if(o) puts("3"); else puts("4");
			}
		}
		else puts(oo?"1":"2");
	}
	return 0;
}