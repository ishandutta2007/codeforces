#include<bits/stdc++.h>
typedef long long ll;
const int L=703,M=1e9+7;
char sc[L];
int d[L],k,f,f1,g,g1,ans;
int main(){
	scanf("%s",sc+1),k=strlen(sc+1);
	for(int i=1;i<=k;i++)d[i]=sc[i]-'0';
	for(int c=0;c<10;c++){
		f=g=g1=0,f1=1;
		for(int i=1;i<=k;i++){
			g=(g*(ll)(100-9*c)+g1*(ll)(c<d[i]?10*d[i]-9*c:d[i])+f+f1*(c<d[i]))%M;
			f=(f*(ll)(91-9*c)+f1*(ll)(c<d[i]?10*d[i]-9*c-9:d[i]))%M;
			g1=(g1*(ll)(d[i]<c?1:10)+f1*(c==d[i]))%M;
			f1=(f1*(ll)(d[i]<=c?1:10))%M;
		}
		ans=(ans+(ll)c*(g+g1))%M;
	}
	printf("%d\n",ans);
	return 0;
}