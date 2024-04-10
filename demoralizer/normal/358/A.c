#include <stdio.h>
#include <string.h>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
int bw(int t,int x,int n){
	return ((t<x&&t>n)||(t>x&&t<n));
}
int main(){
	int n,a=0,b=0,f,s,t,gx,gn,lx,ln;
	scanf("%d",&n);
	if(n<4){printf("no");return 0;}
	scanf("%d %d %d",&f,&s,&t);
	if(bw(t,f,s)){
		gx=max(f,s);gn=min(f,s);a=1;
	}
	else{
		lx=max(f,s);ln=min(f,s);b=1;
	}
	f=s;s=t;
	for(int i=0;i<(n-3);i++){
		scanf("%d",&t);
		if((a&&(t>gx||t<gn))||(b&&bw(t,lx,ln)))
			{printf("yes");return 0;}
		if(bw(t,f,s)){
			gx=max(f,s);
			gn=min(f,s);
			a=1;
			if(b){
				if(bw(gx,lx,ln))gx=ln;
				if(bw(gn,lx,ln))gn=lx;
				b=0;
			}
		}
		else if(a){
			if(bw(t,s,gx))gn=s;
			if(bw(t,s,gn))gx=s;
		}
		else if(b){
			lx=max(max(f,s),lx);
			ln=min(min(f,s),ln);
		}
		f=s;s=t;
	}
	printf("no");
}