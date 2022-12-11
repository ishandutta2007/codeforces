#include<bits/stdc++.h>
using namespace std;
char s[12];
int main(){
	int T;cin>>T;while(T--){
		scanf("%s",s+1);
		int am=0,ap=0,bm=0,bp=0,al=5,bl=5;
		for(int i=1;i<=10;++i){
			if(i&1)am+=s[i]=='1',ap+=s[i]=='?';
			else bm+=s[i]=='1',bp+=s[i]=='?';
			al-=i&1; bl-=i&1^1;
			if(am+ap>bm+bl){printf("%d\n",i);goto d;}
			if(bm+bp>am+al){printf("%d\n",i);goto d;}
		}puts("10");d:;
	}
}