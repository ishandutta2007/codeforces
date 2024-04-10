#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,ra,rb,ans;char str[N];
int main(){
	scanf("%d%d%d",&n,&ra,&rb);scanf("%s",str+1);
	for(int i=1,lst=-1;i<=n;i++){
		if(str[i]=='*')lst=-1;
		else if(str[i]=='.'){
			if(lst!=-1){
				if(!lst){if(rb)rb--,ans++,lst=1;else lst=-1;}
				else{if(ra)ra--,ans++,lst=0;else lst=-1;}
			}else{
				if(ra>rb)lst=0,ra--,ans++;else lst=1,rb--,ans++;
			}
		}
		if(!ra&&!rb)break;
	}
	printf("%d\n",ans);
	return 0;
}