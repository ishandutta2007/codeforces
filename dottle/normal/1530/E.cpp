#include<bits/stdc++.h>
const int N=200050;
using namespace std;

char a[N];
int t,c[N],mx,n; 

void pc(int k){
	putchar(k+'a'),c[k]--;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",a),n=strlen(a);
		for(int i=0;i<26;i++)c[i]=0;
		for(int i=0;i<n;i++)c[a[i]-'a']++;
		int fl=0;
		for(int i=0;i<26&&!fl;i++)if(c[i]==1){
			putchar(i+'a'),c[i]=0;
			for(int j=0;j<26;j++)
				for(int k=0;k<c[j];k++)
					putchar(j+'a');
			fl=1,putchar('\n');
		}
		if(fl)continue;
		int ft=0,sc=0,td=0;
		for(int i=0;i<26;i++)
			if(c[i]){ft=i;break;}
		for(int i=ft+1;i<26;i++)if(c[i]){sc=i;break;}
		if(!sc){printf("%s\n",a);continue;}
		else {for(int i=sc+1;i<26;i++)if(c[i]){td=i;break;}else; }
		
			if(c[ft]>n/2+1){
				pc(ft),pc(sc);
				if(td){
					while(c[ft])pc(ft);
					pc(td);
					for(int j=sc;j<26;j++)while(c[j])pc(j);
				}else {
					while(c[sc])pc(sc);
					while(c[ft])pc(ft);
				}
			}else{
				pc(ft),pc(ft);
				while(c[ft]){
					for(int j=ft+1;j<26;j++)if(c[j]){pc(j);break;}
					pc(ft);
				}
				for(int j=sc;j<26;j++)while(c[j])pc(j);
			}
		putchar('\n');
	}
}