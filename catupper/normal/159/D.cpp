#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define min(a,b) (a<b?a:b)
char s[2000];
int c[2000],cl[2000],l;
long long int res=0;

long long int x(long long int a){return a*(a-1)/2+a;}

int main(){
	scanf("%s",s);
	l=strlen(s);
	for(int a=0;a<l;a++){
		while(a+c[a]<l && a-c[a]>=0 && s[a+c[a]]==s[a-c[a]])	c[a]++;
	    while(a+cl[a]+1<l && a-cl[a]>=0 && s[a+cl[a]+1]==s[a-cl[a]])	cl[a]++;
	}
	for(int a=0;a<l;a++){
		for(int b=a+1;b<l;b++){
			int t,u,tl,ul;
	        t=min(c[a],b-a);
	        u=min(c[b],b-a);
	        tl=min(cl[a],b-a-1);
	        ul=min(cl[b],b-a);
			res+=t*u;
			if(t+u>b-a+1)res-=x(t+u-(b-a+1));
			if(ul){
				res+=t*ul;
				if(t+ul>b-a+1)res-=x(t+ul-(b-a+1));
			}
			if(tl){
				res+=tl*u;
				if(tl+u>b-a)res-=x(tl+u-(b-a));
			}
			if(ul && tl){
				res+=tl*ul;
				if(tl+ul>b-a)res-=x(tl+ul-(b-a));
			}
		}
	}
	cout<< res << endl;
	return 0;
}