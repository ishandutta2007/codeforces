#include<cstdio>
#include<cstring>
#define maxx(a,b) ((a)>(b)?(a):(b))
#define minn(a,b) ((a)<(b)?(a):(b))
#define abss(a) ((a)<0?-(a):(a))

int tables[26][26],N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char S[100];		
		scanf("%s",S);
		int len=strlen(S);
		int st=S[0]-'a',go=S[len-1]-'a';
		for(int i=0;i<26;i++){
			if(tables[i][st]!=0 || i==st)tables[i][go]=maxx(tables[i][go],tables[i][st]+len);
		}	
	}
	int res=0;
	for(int i=0;i<26;i++){
		res=maxx(tables[i][i],res);
	}
	printf("%d\n",res);
	return 0;
	
}