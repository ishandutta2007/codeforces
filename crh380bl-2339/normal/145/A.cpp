#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
//int c[100005];
int main(){
	scanf("%s%s",&a,&b);
	int n=strlen(a),i,s1=0,s2=0;
	for(i=0;i<n;++i){
		s1+=(a[i]=='4'&&b[i]=='7');
		s2+=(a[i]=='7'&&b[i]=='4'); 
	}
	printf("%d\n",max(s1,s2));
	return 0;
}