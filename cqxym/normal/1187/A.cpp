#include<cstdio>
int Min(int x,int y){
	return x<y?x:y;
}
void Sol(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a+1-Min(b,c));
}
int main(){
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Sol();
	}
	return 0;
}