#include<cstdio>
using namespace std;
int num;
int p[50],yes_num[10];
bool yes[10];
bool pd(int a,int b,int c,int d){
	if ((p[a]==p[b])&&(p[c]==p[d])&&(p[a]==p[c]))return 1;
	return 0;
}
int main(){
	for (int i=0;i<6;i++){
		for (int j=1;j<=4;j++)scanf("%d",&p[i*4+j]);
		if ((p[i*4+1]==p[i*4+2])&&(p[i*4+3]==p[i*4+4])&&(p[i*4+1]==p[i*4+3]))yes[i]=1,yes_num[num++]=i;
	}
	if (num!=2){
		puts("NO");
		return 0;
	}
	if (!((yes[0]&&yes[2])||(yes[1]&&yes[5])||(yes[3]&&yes[4]))){
		puts("NO");
		return 0;
	}
	if ((yes[0]&&yes[2])){
		if (pd(13,14,7,8)){
			if (!pd(5,6,19,20)){
				puts("NO");
				return 0;
			}
			if (!pd(17,18,23,24)){
				puts("NO");
				return 0;
			}
			if (!pd(21,22,15,16)){
				puts("NO");
				return 0;
			}
			puts("YES");
			return 0;
		}else{
			if (pd(13,14,23,24)){
				if (!pd(5,6,15,16)){
					puts("NO");
					return 0;
				}
				if (!pd(17,18,7,8)){
					puts("NO");
					return 0;
				}
				if (!pd(21,22,19,20)){
					puts("NO");
					return 0;
				}
				puts("YES");
				return 0;
			}else {
				puts("NO");
				return 0;
			}
		}
	}
	if ((yes[1]&&yes[5])){
		if (pd(3,4,13,15)){
			if (!pd(14,16,11,12)){
				puts("NO");
				return 0;
			}
			if (!pd(9,10,18,20)){
				puts("NO");
				return 0;
			}
			if (!pd(17,19,1,2)){
				puts("NO");
				return 0;
			}
			puts("YES");
			return 0;
		}else{
			if (pd(3,4,18,20)){
				if (!pd(17,19,11,12)){
					puts("NO");
					return 0;
				}
				if (!pd(9,10,13,15)){
					puts("NO");
					return 0;
				}
				if (!pd(14,16,1,2)){
					puts("NO");
					return 0;
				}
				puts("YES");
				return 0;
			}else {
				puts("NO");
				return 0;
			}
		}
	}
	if ((yes[3]&&yes[4])){
		if (pd(1,3,6,8)){
			if (!pd(5,7,10,12)){
				puts("NO");
				return 0;
			}
			if (!pd(9,11,21,23)){
				puts("NO");
				return 0;
			}
			if (!pd(22,24,2,4)){
				puts("NO");
				return 0;
			}
			puts("YES");
			return 0;
		}else{
			if (pd(1,3,21,23)){
				if (!pd(5,7,2,4)){
					puts("NO");
					return 0;
				}
				if (!pd(9,11,6,8)){
					puts("NO");
					return 0;
				}
				if (!pd(22,24,10,12)){
					puts("NO");
					return 0;
				}
				puts("YES");
				return 0;
			}else {
				puts("NO");
				return 0;
			}
		}
	}
	return 0;
}