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
const int MX=1e8;
long long getpow(long long x,int p){
	long long res=1;
	for (int i=1;i<=p;i++){
		res=res*x;
		if (res>MX) return MX;
	}
	return res;
}
int mygcd(int x,int y){
	if (y) return mygcd(y,x%y);
	return x;
}
int main(){
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	if (n==1){
		printf("%d\n",(r-l+1));
	}
	else if (n==2){
		long long res=(LL)(r-l+1)*(LL)(r-l);
		printf("%I64d\n",res);
	}
	else{
		n--;
		long long ans=0;
		for (int a=1;a<=10000;a++){
			long long p=getpow((LL)a,n);
			if (!(p<=r)) continue;
			int lf1=(l-1)/p+1;
			int rg1=r/p; 
			for (int b=1;b<=10000;b++){
				if (mygcd(a,b)!=1) continue;
				if (a==1 && b==1) continue;
				long long p2=getpow((LL)b,n);
				if (!(p2<=r)) continue; 
				int lf2=(l-1)/p2+1;
				int rg2=r/p2;
				int lf=max(lf1,lf2),rg=min(rg1,rg2);
				//cout<<p<<' '<<p2<<' '<<lf<<' '<<rg<<' '<<endl;
				if (lf<=rg){
					ans+=(rg-lf+1);
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}