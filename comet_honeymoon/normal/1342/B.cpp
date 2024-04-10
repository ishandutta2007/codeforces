#include<bits/stdc++.h>
using namespace std;

int T,N;
char t[105];
int cnt0=0;char ANS0[205];
int cnt1=0;char ANS1[205];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",t+1);
		N=strlen(t+1);
		bool flg=1;
		for(int i=1;i<=N;i++) flg&=(t[i]==t[1]);
		if(flg){
			for(int i=1;i<=N;i++) printf("%c",t[i]);
			printf("\n");
			continue;
		}
		cnt0=0;
		for(int i=1;i<=N;i++){
			if(t[i]=='1') ANS0[++cnt0]='0',ANS0[++cnt0]='1';
			else if(i<N&&t[i+1]=='1') i++,ANS0[++cnt0]='0',ANS0[++cnt0]='1';
			else ANS0[++cnt0]='0',ANS0[++cnt0]='1';
		}
		cnt1=0;
		for(int i=1;i<=N;i++){
			if(t[i]=='0') ANS1[++cnt1]='1',ANS1[++cnt1]='0';
			else if(i<N&&t[i+1]=='0') i++,ANS1[++cnt1]='1',ANS1[++cnt1]='0';
			else ANS1[++cnt1]='1',ANS1[++cnt1]='0';
		}
		if(cnt0<cnt1){
			for(int i=1;i<=cnt0;i++) printf("%c",ANS0[i]);
			printf("\n");
		}
		else{
			for(int i=1;i<=cnt1;i++) printf("%c",ANS1[i]);
			printf("\n");
		}
	}
}