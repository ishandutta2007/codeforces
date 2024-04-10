#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool f[30]={0};
	for(int b=0;b<s.length();b++){
		f[(int)s[b]-96]=true;
	}
	string ss;
	cin>>ss;
	int n;
	scanf("%d",&n);
	while(n--){
		string s1;
		cin>>s1;
		for(int b=0,b1=0;b<ss.length();b++,b1++){
			if(ss[b]=='?'){
				if(!f[s1[b1]-96]){
					printf("NO\n");
					break;
				}
			}
			else if(ss[b]=='*'){
				int c=0;
				while(!f[s1[b1]-96]&&b1<s1.length()&&c<s1.length()-ss.length()+1){
					b1++;c++;
				}
				b1--;
			}
			else if(ss[b]!=s1[b1]){
				printf("NO\n");
				break;
			}
			if(b==ss.length()-1)
			    if(b1==s1.length()-1){
				    printf("YES\n");
			    }
			     else printf("NO\n");
		}
	}
}