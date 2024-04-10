#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	printf("YES\n");
	if(t[0]==t[1])swap(s,t);
	if(s[0]==s[1]){
		if(t[0]==s[0]||t[1]==s[0]){
			char rep=s[0];
			char oth;
			char fir;
			if(t[0]==t[1]){
				if(s[0]=='a'){
					oth='b';
					fir='c';
				}
				else if(s[0]=='b'){
					oth='a';
					fir='c';
				}
				else{
					oth='a';
					fir='b';
				}
			}
			else{
				if(t[0]==s[0]){
					fir=t[1];
				}
				else{
					fir=t[0];
				}
				if('a'!=t[1]&&'a'!=t[0])oth='a';
				else if('b'!=t[1]&&'b'!=t[0])oth='b';
				else oth='c';
			}
			for(int i=0;i<n;i++){
				printf("%c",fir);
			}
			for(int i=0;i<2*n;i++){
				if(i%2)printf("%c",rep);
				else printf("%c",oth);
			}
		}
		else if(t[0]==t[1]){
			char oth;
			if('a'!=t[1]&&'a'!=s[0])oth='a';
			else if('b'!=t[1]&&'b'!=s[0])oth='b';
			else oth='c';
			for(int i=0;i<n;i++){
				printf("%c",oth);
			}
			for(int i=0;i<2*n;i++){
				if(i%2)printf("%c",s[0]);
				else printf("%c",t[0]);
			}
		}
		else{
			char rep=s[0];
			char oth;
			char fir;
			if(s[0]=='a'){
				oth='b';
				fir='c';
			}
			else if(s[0]=='b'){
				oth='a';
				fir='c';
			}
			else{
				oth='a';
				fir='b';
			}
			for(int i=0;i<n;i++){
				printf("%c",fir);
			}
			for(int i=0;i<2*n;i++){
				if(i%2)printf("%c",oth);
				else printf("%c",rep);
			}
		}
	}
	else{
		if(s[0]==t[1]&&s[1]==t[0]){
			for(int i=0;i<n;i++){
				printf("%c",s[0]);
			}
			char oth;
			if('a'!=s[1]&&'a'!=s[0])oth='a';
			else if('b'!=s[1]&&'b'!=s[0])oth='b';
			else oth='c';
			for(int i=0;i<n;i++){
				printf("%c",oth);
			}
			for(int i=0;i<n;i++){
				printf("%c",s[1]);
			}
		}
		else if(s[0]==t[0]){
			char oth;
			char fir;
			if(s[0]=='a'){
				oth='b';
				fir='c';
			}
			else if(s[0]=='b'){
				oth='a';
				fir='c';
			}
			else{
				oth='a';
				fir='b';
			}
			for(int i=0;i<n;i++){
				printf("%c",fir);
			}
			for(int i=0;i<n;i++){
				printf("%c",oth);
			}
			for(int i=0;i<n;i++){
				printf("%c",s[0]);
			}
		}
		else if(s[1]==t[1]){
			char oth;
			char fir;
			if(s[1]=='a'){
				oth='b';
				fir='c';
			}
			else if(s[1]=='b'){
				oth='a';
				fir='c';
			}
			else{
				oth='a';
				fir='b';
			}
			for(int i=0;i<n;i++){
				printf("%c",s[1]);
			}
			for(int i=0;i<n;i++){
				printf("%c",oth);
			}
			for(int i=0;i<n;i++){
				printf("%c",fir);
			}
		}
		else{
			if(s[1]==t[0])swap(s,t);
				for (int i = 0; i < n; i++) {
					printf("%c", s[1]);
				}
				for (int i = 0; i < n; i++) {
					printf("%c", s[0]);
				}
				for (int i = 0; i < n; i++) {
					printf("%c", t[0]);
				}
		}
	}
    return 0;
}