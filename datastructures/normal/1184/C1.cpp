#include <iostream>
#include <cstdio>
using namespace std;
int x[55],y[55],n;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	for (int i=1;i<=4*n+1;i++)cin>>x[i]>>y[i];
	for (int xi=0;xi<=50;xi++)
		for (int xj=xi;xj<=50;xj++)
			for (int yi=0;yi<=50;yi++)
				for (int yj=yi;yj<=50;yj++){
					int ansx,ansy,cnt=0;
					for (int k=1;k<=4*n+1;k++)	
						if (!(((x[k]==xi)&&y[k]>=yi&&y[k]<=yj)||((x[k]==xj)&&y[k]>=yi&&y[k]<=yj)||((y[k]==yi)&&x[k]>=xi&&x[k]<=xj)||((y[k]==yj)&&x[k]>=xi&&x[k]<=xj)))
							ansx=x[k],ansy=y[k],cnt++;
					if (cnt==1){
						cout<<ansx<<' '<<ansy<<endl;
						return 0;
					}
				}
	return 0;
}