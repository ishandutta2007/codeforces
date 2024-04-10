#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,m,i,j,lk[800005],t,cnt,v[800005];
vector<pair<int,int> > bi[800005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		fz1(i,n+n+n){
			lk[i]=0;
			bi[i].clear();
		}
		fz1(i,m){
			int x,y;v[i]=0;
			scanf("%d%d",&x,&y);
			bi[x].push_back(make_pair(y,i));
			bi[y].push_back(make_pair(x,i));
		}
		cnt=0;
		fz1(i,n+n+n)if(!lk[i]){
			ff(bi[i],it){
				if(!lk[it->first]){
					lk[i]=it->first;
					lk[it->first]=i;
					cnt++;v[it->second]=1; 
					break;
				}
			}
		}
		if(cnt<n){
			puts("IndSet");
			int t=n;
			fz1(i,n+n+n){
				if(!lk[i]){
					if(t>0){
						t--;
						printf("%d%c",i,t?' ':'\n');
					}
				}
			}
		}
		else{
			puts("Matching");
			int t=n;
			fz1(i,m){
				if(v[i]){
					if(t>0){
						t--;
						printf("%d%c",i,t?' ':'\n');
					}
				}
			}
		}
	} 
	return 0;
}