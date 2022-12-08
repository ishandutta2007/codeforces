#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5005];
ll sum=0;
bool f[5005][5005];
bool rec[5005][5005];
bool use[5005];
int main() {
	int n,k,v,i,j;
	scanf("%d%d%d",&n,&k,&v);
	for(i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(sum<v) 
		puts("NO");
	 else if (sum==v||v==0) {
		puts("YES");
		for(i=2; i<=n; i++)
			if(a[i]>0) printf("%d %d 1\n",int(ceil(1.0*a[i]/k)),i);
	} else {
		int need=v%k;
		f[0][0] = true;
		for(i=1; i<=n; i++) {
			int r = a[i]%k;
			for(j=0; j<k; j++) {
				f[i][j] = f[i-1][j];
			}
			for(j=0; j<k; j++) {
				if(f[i-1][j] && !f[i][(j+r)%k]) {
					f[i][(j+r)%k] = true;
					rec[i][(j+r)%k] = true;
				}
			}
		}
		if(f[n][need]==false)puts("NO");
		else {
			j = need; vector<int>vec;
			vec.clear();
			while(i) {
				if(rec[i][j]) {
					use[i] = true;
					j -= a[i]%k;
					if(j<0)j+=k;
					vec.push_back(i);
				}
				i -- ;
			}
			if(vec.size()==0) {
				puts("YES");
				for(i=2; i<=n; i++)
					if(a[i]>0) printf("%d %d 1\n",int(ceil(1.0*a[i]/k)),i);
				printf("%d 1 2\n",v/k);
			} else {
				puts("YES");
				int pos = vec[0],pos2;
				for(i=1; i<(int)vec.size(); i++)
					if(a[vec[i]]>0) printf("%d %d %d\n",int(ceil(1.0*a[vec[i]]/k)),vec[i],pos),a[pos]+=a[vec[i]],a[vec[i]]=0;
				if(pos==1) pos2 = 2;
				else pos2=1;
				if(a[pos]>v) {
					printf("%lld %d %d\n",(a[pos]-v)/k,pos,pos2);
				} else if(a[pos]<v) {
					for(i=1; i<=n; i++)if(i!=pos&&i!=pos2&&!use[i]&&a[i]>0)printf("%d %d %d\n",int(ceil(1.0*a[i]/k)),i,pos2);
					printf("%lld %d %d\n",(v-a[pos])/k,pos2,pos);
				}
			}
		}
	}
	getchar(),getchar();
	return 0;
}