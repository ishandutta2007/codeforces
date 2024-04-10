#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int M=2000010;
const int md=1000007;
int last[md];
char x[M][9],y[M][9];
int z[M],pred[M];
char grid[22][22],gr[22][22];
int hh[M],len,n,m,i,e,ii,jj,j;
long long h[M];
void hashh(int q){
	h[q]=0;
	for (int i=0;i<len;i++) h[q]=(h[q]*239017+x[q][i])*239017+y[q][i];
	hh[q]=h[q]%md;
	if (hh[q]<0) hh[q]+=md;
}
int main(){
	scanf ("%d%d",&n,&m);
	len=0;
	for (ii=0;ii<n;ii++)
		for (jj=0;jj<m;jj++) {
			char ch=getchar();
			while (ch!='#' && ch!='.' && ch!='@' && (ch<'0' || ch>'9')) ch=getchar();
			if (ch>='0' && ch<='9'){
				x[1][ch-49]=ii;
				y[1][ch-49]=jj;
				if (ch-48>len) len=ch-48;
				ch='.';
			}
			grid[ii][jj]=ch;
		}
	memset(last,0,sizeof(last));
	i=1,e=1;
	z[1]=0;
	hashh(1);
	last[hh[1]]=1;
	while (i<=e){
		for (ii=0;ii<n;ii++)
			for (jj=0;jj<m;jj++)
				gr[ii][jj]=grid[ii][jj];
		for (j=0;j<len-1;j++) gr[x[i][j]][y[i][j]]='7';
		for (int qj=0;qj<4;qj++){
			int xk=x[i][0]+dx[qj],yk=y[i][0]+dy[qj];
			if (xk>=0 && yk>=0 && xk<n && yk<m){
				if (gr[xk][yk]=='@'){
					printf("%d\n",z[i]+1);
					exit(0);
				}
				if (gr[xk][yk]=='.'){
					for (j=0;j<len-1;j++) x[e+1][j+1]=x[i][j],y[e+1][j+1]=y[i][j];
					x[e+1][0]=xk;
					y[e+1][0]=yk;
					hashh(e+1);
					int ok=1;
					j=last[hh[e+1]];
					while (j>0){
						if (h[e+1]==h[j]){
							ok=0;
							break;
						}
						j=pred[j];
					}
					if (ok){
						e++;
						z[e]=z[i]+1;
						pred[e]=last[hh[e]];
						last[hh[e]]=e;
					}
				}
			}
		}
		i++;
	}
	printf("%d\n",-1);
}