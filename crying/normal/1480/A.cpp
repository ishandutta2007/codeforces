#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep for(ll i=(a);i<=(b);i++)
#define pre for(ll i=(b);i>=(a);i--)
using namespace std;
typedef long long ll;
int T;
char tmp[100];
int main(){
	cin>>T;
	while(T--){
		cin>>tmp;
		for(int i=0;i<strlen(tmp);i++){
			if(i&1){
				//b
				if(tmp[i]=='z')printf("y");
				else printf("z");
			}else{
				//a
				if(tmp[i]=='a')printf("b");
				else printf("a");
			}
		}
		printf("\n");
	}
	
	return 0;
}