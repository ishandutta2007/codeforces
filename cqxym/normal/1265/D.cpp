#include<stdio.h>
#define R register int
int ans[100001];
inline bool Try1(int a,int b,int c,int d){
	int st;
	if(a==0){
		if(b==0){
			if(c==0||d==0){
				return false;
			}
			st=3;
		}else{
			if(c==0&&d==0){
				return false;
			}else{
				if(c==0){
					st=3;
				}else{
					st=2;
				}
			}
		}
	}else{
		if(b==0){
			if(c==0&&d==0){
				return false;
			}
			if(c==0){
				st=3;
			}else{
				st=2;
			}
		}else{
			st=1;
		}
	}
	int ct=0;
	while(a+b+c+d>1){
		ans[ct]=st;
		ct++;
		if(st==0){
			a--;
		}else if(st==1){
			b--;
		}else if(st==2){
			c--;
		}else{
			d--;
		}
		if(st==0){
			if(b==0){
				return false;
			}
			st=1;
		}else if(st==1){
			if(a==0&&c==0){
				return false;
			}
			if(a!=0){
				st=0;
			}else{
				st=2;
			}
		}else if(st==2){
			if(b==0&&d==0){
				return false;
			}
			if(b!=0){
				st=1;
			}else{
				st=3;
			}
		}else{
			if(c==0){
				return false;
			}
			st=2;
		}
	}
	puts("YES");
	for(R i=0;i<ct;i++){
		printf("%d ",ans[i]);
	}
	if(a==1){
		puts("0");
	}else if(b==1){
		puts("1");
	}else if(c==1){
		puts("2");
	}else{
		puts("3");
	}
	return true;
}
inline bool Try2(int a,int b,int c,int d){
	int st;
	if(a==0){
		if(b==0){
			if(c==0){
				st=3;
			}else{
				st=2;
			}
		}else{
			st=1;
		}
	}else{
		st=0;
	}
	int ct=0;
	while(a+b+c+d>1){
		ans[ct]=st;
		ct++;
		if(st==0){
			a--;
		}else if(st==1){
			b--;
		}else if(st==2){
			c--;
		}else{
			d--;
		}
		if(st==0){
			if(b==0){
				return false;
			}
			st=1;
		}else if(st==1){
			if(a==0&&c==0){
				return false;
			}
			if(a!=0){
				st=0;
			}else{
				st=2;
			}
		}else if(st==2){
			if(b==0&&d==0){
				return false;
			}
			if(b!=0){
				st=1;
			}else{
				st=3;
			}
		}else{
			if(c==0){
				return false;
			}
			st=2;
		}
	}
	puts("YES");
	for(R i=0;i<ct;i++){
		printf("%d ",ans[i]);
	}
	if(a==1){
		puts("0");
	}else if(b==1){
		puts("1");
	}else if(c==1){
		puts("2");
	}else{
		puts("3");
	}
	return true;
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(Try1(a,b,c,d)==false){
		if(Try2(a,b,c,d)==false){
			printf("NO");
		}
	}
	return 0;
}