#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Fwt{
	int T[202020];
	int Push(int idx,int val)
	{
		for(;idx<=2e5;idx+=(idx&-idx)){
			T[idx] += val;
		}

		return 0;
	}

	int Get(int idx)
	{
		int ret = 0;

		for(;idx;idx-=(idx&-idx)){
			ret += T[idx];
		}

		return ret;
	}

	int Sum(int l,int r)
	{
		return Get(r) - Get(l-1);
	}
};

Fwt K[4][11][11];
string s,ts;
int S[101010];
int n;

int main()
{
	cin.sync_with_stdio(0);

	int i,j,l,c,r,a,t,ans;
	char ch;

	cin >> s >> n;

	for(i=0;i<s.size();i++){
		if(s[i] == 'A') S[i+1] = 0;
		if(s[i] == 'T') S[i+1] = 1;
		if(s[i] == 'G') S[i+1] = 2;
		if(s[i] == 'C') S[i+1] = 3;

		for(j=1;j<=10;j++){
			K[S[i+1]][j][(i+1)%j].Push(i+1,1);
		}
	}

	for(i=0;i<n;i++){
		cin >> t;
		if(t == 1){
			cin >> a >> ch;
			if(ch == 'A') c = 0;
			if(ch == 'T') c = 1;
			if(ch == 'G') c = 2;
			if(ch == 'C') c = 3;

			for(j=1;j<=10;j++){
				K[S[a]][j][a%j].Push(a,-1);
				K[c][j][a%j].Push(a,1);
			}

			S[a] = c;
		}
		else{
			cin >> l >> r >> ts;
			for(ans=j=0;j<ts.size();j++){
				if(ts[j] == 'A') c = 0;
				if(ts[j] == 'T') c = 1;
				if(ts[j] == 'G') c = 2;
				if(ts[j] == 'C') c = 3;

				ans += K[c][ts.size()][(l+j)%ts.size()].Sum(l,r);
			}
			printf("%d\n",ans);
		}
		//printf("%d\n",K[1][2][0].T[16]);
	}

	return 0;
}