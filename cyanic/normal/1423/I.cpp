#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=600010;
struct S {
	int dl,dr,gl,gr,v;
}s[MAXN];
int k,q,z,cnt,fgl[1<<17],fgh[1<<17],dgl[1<<17],dgh[1<<17];
ll x,y;
pair<int,int> fct (ll x) {
	return make_pair(x&((1ll<<k)-1),x>>k);
}
int main () {
	scanf("%d%d",&k,&q);
	for (int i=1;i<=q;i++) {
		scanf("%lld%lld%d",&x,&y,&z);
		pair<int,int> a=fct(x),b=fct(y);
		if (a.second==b.second) {
			cnt++;
			s[cnt].dl=a.first,s[cnt].dr=b.first,s[cnt].gl=s[cnt].gr=a.second,s[cnt].v=z;
		} else {
			cnt++;
			s[cnt].dl=a.first,s[cnt].dr=(1<<k)-1,s[cnt].gl=s[cnt].gr=a.second,s[cnt].v=z;
			cnt++;
			s[cnt].dl=0,s[cnt].dr=b.first,s[cnt].gl=s[cnt].gr=b.second,s[cnt].v=z;
			if (a.second+1<=b.second-1) {
				cnt++;
				s[cnt].dl=0,s[cnt].dr=(1<<k)-1,s[cnt].gl=a.second+1,s[cnt].gr=b.second-1,s[cnt].v=z;
			}
		}
	}
	for (int i=0;i<16;i++) {
		memset(fgl,0,sizeof(fgl));
		memset(fgh,0,sizeof(fgh));
		for (int j=1;j<=cnt;j++) {
			if (s[j].v&(1<<i)) {
				fgl[s[j].dl]++,fgl[s[j].dr+1]--;
				fgh[s[j].gl]++,fgh[s[j].gr+1]--;
			}
		}
		dgl[0]+=(fgl[0]!=0)*(1<<i);
		dgh[0]+=(fgh[0]!=0)*(1<<i);
			//cout << i << "  " << 0 << "  " << fgl[0] << "  " << fgh[0] << endl;
		for (int j=1;j<(1<<k);j++) {
			fgl[j]+=fgl[j-1],fgh[j]+=fgh[j-1];
			fgl[j-1]=min(fgl[j-1],1),fgh[j-1]=min(fgh[j-1],1);
			//cout << i << "  " << j << "  " << fgl[j] << "  " << fgh[j] << endl;
			if (fgl[j]) {dgl[j]+=(1<<i);}
			if (fgh[j]) {dgh[j]+=(1<<i);}
		}
		fgl[(1<<k)-1]=min(fgl[(1<<k)-1],1),fgh[(1<<k)-1]=min(fgh[(1<<k)-1],1);
		for (int j=1;j<(1<<k);j++) {fgl[j]+=fgl[j-1],fgh[j]+=fgh[j-1];}
		for (int j=1;j<=cnt;j++) {
			if (!(s[j].v&(1<<i))) {
				if (fgl[s[j].dr]-(s[j].dl==0?0:fgl[s[j].dl-1])!=0&&fgh[s[j].gr]-(s[j].gl==0?0:fgh[s[j].gl-1])!=0) {
					//cout << i << "  " << j << "  " << s[j].dr << "  " << s[j].dl << "  " << fgl[s[j].dr]-(s[j].dl==0?0:fgl[s[j].dl-1]) << endl;
					printf("impossible\n");
					return 0;
				}
			}
		}
	}
	printf("possible\n");
	for (int i=0;i<(1<<k);i++) {
		printf("%d\n",dgl[i]);
	}
	for (int i=0;i<(1<<k);i++) {
		printf("%d\n",dgh[i]);
	}
	return 0;
}