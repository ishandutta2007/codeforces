/*
	xx



  







 

*/
/*



 . 











	 
 
...

.

 
{
^ma
|zzzz|



z|||z


	


M





}{

 
 


 M M M
/M
    
   
Wiiiiiiii M 
dpppppppp


q-rq-rq---rq-rq-rq---rqr
q--sq-r
t-st-r
q-rq-st--rt--r
t--rt-sts
t-st-st---st----st----st---s 

jTTjXTrTmTrTjTUTTpTrXXmrX
dTTgUUtTaUUUUUUtTUUtT
dTTgUUtTaaUUUUUUUXdTgX
mTTptTaXTrUUdstpTTpTmtTtTatT
TTTjTTsUUUUUUXarTTTpTTT
TTpTTUUUmmTUUUUU U
TTTmTTTtTapTTTUtatataU ^s

------
--
--------
--


qTTTTTTr
U   U
Ute
U  
Uqe 
U / U
tTTTTTTs 
~*~*~
*~*~

v

v
v

vv?
vv
v
vv
v
v
v
v
v

??
???
???
__ __?
nnn?

nnnn?




..o+?''o?''oso+?''o?''o
X--[XT-YX-[q-TrXT-[V[
V-_V[^-_WTsXYX-a
^-[\`X-[^-[
X-_qT_
\_\_^-_\tTs\_\`^-T_
o+?''o?''oso+?''o?''o

XTT[X[X[X[
^[XaUUXTjjjT[U^adTjj[
Xa^[U^gUUUUdg^[XgUUUU
^TTa^TmTmTmTa^a^TmTa

	


 



M     M M
<  >    
     MM 

 qrqr

q-------r



ts
t-s
t-------s
 qrqr
 t----s

..


..
..

""


ts




















*/

/*
			  ********
               ************
               ####....#.
             #..###.....##....
             ###.......######              ###                 ###           ###           ###
                ...........               #...#               #...#         #...#         #...#
               ##*#######                 #.#.#               #.#.#         #.#.#         #.#.#
            ####*******######             #.#.#               #.#.#         #.#.#         #.#.#
           ...#***.****.*###....          #...#               #...#         #...#         #...#
           ....**********##.....           ###                 ###           ###           ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################              ##################################
#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#
###########################################------------------#              ###############------------------#
#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################
##########################################    #----------#                  ##############    #----------#
#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#
##########################################    #----------#                  ##############    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#
##########################################    ############                  ##############    ############
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
const int Maxn=105;
long long cnt[Maxn][Maxn];
int main(){
	int n,m,x,y;
	long long k;
	scanf("%d %d %I64d %d %d",&n,&m,&k,&x,&y);
	if (n==1){
		int round=m;
		long long rr=k/(LL)round;
		for (int j=1;j<=m;j++){
			cnt[1][j]=rr;
		}
		k-=(LL)rr*(LL)round;
		for (int i=1;i<=k;i++){
			cnt[1][i]++;
		}
		long long Max=0,Min=2e18; 
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				Max=max(Max,cnt[i][j]);
				Min=min(Min,cnt[i][j]);
			}
		}
		printf("%I64d %I64d %I64d",Max,Min,cnt[x][y]);
		return 0;
	}
	int round=(2*n-2)*m;
	//cout<<round<<endl;
	long long rr=k/(LL)round;
	//cout<<rr<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (i==1 || i==n) cnt[i][j]=rr; else cnt[i][j]=rr*2;
		}
	}
	k-=(LL)rr*(LL)round;
	for (int i=1;i<2*n-1;i++){
		int ii=i;
		if (ii>n) ii=2*n-i;
		for (int j=1;j<=m;j++){
			if (k==0LL){
				break;
			}
			k--;
			cnt[ii][j]++;
		}
		if (!k) break;
	}
	long long Max=0,Min=2e18; 
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			Max=max(Max,cnt[i][j]);
			Min=min(Min,cnt[i][j]);
		}
	}
	//cout<<x<<y<<endl;
	printf("%I64d %I64d %I64d",Max,Min,cnt[x][y]);
	return 0;
}