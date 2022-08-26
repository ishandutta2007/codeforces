#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,op,y;
double sum,x;
vector<double> seq,seq2;
int main()
{
	scanf("%d",&n);
	seq.push_back(0);
	seq2.push_back(0);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%lf",&y,&x);
			seq2[y-1]+=x;
			sum+=y*x;
		}
		if (op==2)
		{
			scanf("%lf",&x);
			seq.push_back(x);
			seq2.push_back(0);
			sum+=x;
		}
		if (op==3)
		{
			if (seq.size()!=1) seq2[seq.size()-2]+=seq2[seq.size()-1];
			sum-=seq[seq.size()-1];
			sum-=seq2[seq.size()-1];
			seq.pop_back();
			seq2.pop_back();
		}
		//for (j=0;j<seq.size();j++) cerr<<seq[j]<<' ';cerr<<endl;
		//for (j=0;j<seq2.size();j++) cerr<<seq2[j]<<' ';cerr<<endl;
		printf("%.20f\n",sum/((double)seq.size()));
	}
	return 0;
}