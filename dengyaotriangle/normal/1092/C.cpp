#include<iostream>
#include<cstring>

using namespace std;

const int maxn=205;

int n;
char s[maxn][maxn];
int l[maxn];
char d[maxn];
char ans[maxn];
bool pl[maxn],sl[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n+n-2;i++) cin>>s[i];
	for(int i=1;i<=n+n-2;i++) l[i]=strlen(s[i]);
	for(int i=1;i<=n+n-2;i++){
		for(int j=1;j<=n+n-2;j++){
			if(i==j) continue;
			if(l[i]==n-1&&l[j]==1){
				for(int k=0;k<n-1;k++)d[k]=s[i][k];
				d[n-1]=s[j][0];
				bool ok=1;
				for(int k=1;k<=n+n-2;k++){
					bool isp=1,iss=1;
					for(int x=0;x<l[k];x++){
						if(s[k][x]!=d[x]) isp=0;
						if(s[k][x]!=d[n-l[k]+x]) iss=0;
					}
					if(isp&&iss){
						ans[k]='A';
					}else if(isp){
						ans[k]='P';
					}else if(iss){
						ans[k]='S';
					}else ok=0;
				} 
				if(ok){
					int cp=0,cs=0;
					memset(pl,0,sizeof(pl));memset(sl,0,sizeof(sl));
					for(int i=1;i<=n+n-2;i++) if(ans[i]=='P') cp++;
					for(int i=1;i<=n+n-2;i++) if(ans[i]=='S') cs++;
					for(int i=1;i<=n+n-2;i++) if(ans[i]=='P') pl[l[i]]=1; 
					for(int i=1;i<=n+n-2;i++) if(ans[i]=='S') sl[l[i]]=1;
					bool ok2=1;
					for(int i=1;i<=n+n-2;i++){
						if(ans[i]=='A'){
							if(cp<n-1&&(!pl[l[i]])){
								cp++;
								pl[l[i]]=1;
								ans[i]='P';
							}else if(cs<n-1&&(!sl[l[i]])){
								cs++;
								sl[l[i]]=1;
								ans[i]='S'; 
							}else ok2=0;
						} 
					} 
					if(!ok2) continue;
					for(int i=1;i<=n+n-2;i++) cout<<ans[i];
					return 0;
				}
			}
		}
	}
	return 0;
}