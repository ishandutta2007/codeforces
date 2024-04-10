#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
int a[100];
bool b[100];
int main(){
	int n,s=0;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(R i=0;i<n;i++){
		if(b[i]==false){
			s++;
			for(R j=0;j<n;j++){
				if(a[j]%a[i]==0){
					b[j]=true;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}